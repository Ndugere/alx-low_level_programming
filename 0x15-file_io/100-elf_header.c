#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char* message) {
    write(STDERR_FILENO, message, strlen(message));
    exit(98);
}

void print_elf_header(const Elf64_Ehdr* header) {
    char buffer[64]; // Temporary buffer for formatting
    int len;

    len = sprintf(buffer, "Magic:   %02x %02x %02x %02x\n",
                  header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
                  header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "Class:                             %s\n",
                  header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
                  header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Unknown");
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "Data:                              %s\n",
                  header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
                  header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown");
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "OS/ABI:                            %s\n",
                  header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "Solaris ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_AIX ? "AIX ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "IRIX ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "FreeBSD ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "TRU64 UNIX ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_MODESTO ? "Novell Modesto ABI" :
                  header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "OpenBSD ABI" : "Unknown");
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "Type:                              0x%x\n", header->e_type);
    write(STDOUT_FILENO, buffer, len);

    len = sprintf(buffer, "Entry point address:               0x%lx\n", header->e_entry);
    write(STDOUT_FILENO, buffer, len);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename\n");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error: Failed to open file\n");
    }

    Elf64_Ehdr* header = (Elf64_Ehdr*)malloc(sizeof(Elf64_Ehdr));
    if (header == NULL) {
        print_error("Error: Failed to allocate memory\n");
    }

    if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        print_error("Error: Failed to read file\n");
    }

    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
        header->e_ident[EI_MAG1] != ELFMAG1 ||
        header->e_ident[EI_MAG2] != ELFMAG2 ||
        header->e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Error: Not an ELF file\n");
    }

    print_elf_header(header);

    free(header);
    close(fd);

    return 0;
}
