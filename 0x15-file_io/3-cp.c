#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * close_errchk - closes a file descriptor and prints an error message if it fails
 * @fd: file descriptor to close
 *
 * Return: 0 if successful, 100 if failed
 */
int close_errchk(int fd)
{
	int err;

	err = close(fd);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Kosa: Haiwezekani kufunga fd %d\n", fd);
		return (100);
	}
	return (0);
}

/**
 * write_err - handles write errors and prints an error message
 * @fd1: first file descriptor
 * @fd2: second file descriptor
 * @filename: name of the file being written to
 *
 * Return: 99
 */
int write_err(int fd1, int fd2, char *filename)
{
	dprintf(STDERR_FILENO, "Kosa: Haiwezekani kuandika kwenye %s\n", filename);
	close_errchk(fd1);
	close_errchk(fd2);
	return (99);
}

/**
 * read_err - handles read errors and prints an error message
 * @fd1: first file descriptor
 * @fd2: second file descriptor
 * @filename: name of the file being read from
 *
 * Return: 98
 */
int read_err(int fd1, int fd2, char *filename)
{
	dprintf(STDERR_FILENO, "Kosa: Haiwezekani kusoma kutoka kwenye faili %s\n", filename);
	close_errchk(fd1);
	close_errchk(fd2);
	return (98);
}

/**
 * main - copies the content of one file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 97 if incorrect number of arguments, 98 if file_from cannot be read,
 *         99 if file_to cannot be written, 100 if closing a file descriptor fails,
 *         0 otherwise
 */
int main(int argc, char *argv[])
{
	char buf[BUFFER_SIZE];
	ssize_t lenr, lenw;
	int file_from, file_to, err;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Matumizi: cp file_from file_to\n");
		return (97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Kosa: Haiwezekani kusoma kutoka kwenye faili %s\n", argv[1]);
		return (98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Kosa: Haiwezekani kuandika kwenye %s\n", argv[2]);
		close_errchk(file_from);
		return (99);
	}

	do {
		lenr = read(file_from, buf, BUFFER_SIZE);
		if (lenr == -1)
			return (read_err(file_from, file_to, argv[1]));
		lenw = write(file_to, buf, lenr);
		if (lenw == -1 || lenw != lenr)
			return (write_err(file_from, file_to, argv[2]));
	} while (lenr == BUFFER_SIZE);

	err = close(file_from);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Kosa: Haiwezekani kufunga fd %d\n", file_from);
		return (100);
	}

	err = close(file_to);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Kosa: Haiwezekani kufunga fd %d\n", file_to);
		return (100);
	}

	return (0);
}

