#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int fd;

int ft_strlen(char *string)
{
    int len = 0;

    while (string[len])
        len++;
    return (len);
}

int ft_err(char *string)
{
	write(2, string, ft_strlen(string));
	return 1;
}

int ft_cdir(char **argv, int i)
{
	if (i != 2)
		return ft_err("error: cd: bad arguments\n");
	if (chdir(argv[1]))
	{
        ft_err("error: cd: cannot change directory to ");
        ft_err(argv[1]);
        ft_err("\n");
        return (1);
    }
	return 0;
}

int ft_ex(char **argv, char **envp, int i)
{
	int fds[2];
	int	res;
	int pip = (argv[i] && !strcmp(argv[i], "|"));
	
	if (pip && pipe(fds) == -1)
	{
		ft_err("error: fatal\n");
		return (1);
	}
	int pid = fork();
	// si no se ha podido hacer un fork: 
	// (1) hacemos un dup2 para poder mostrar por pantalla
	// (2) cerramos el fd
	// (3) si es un pipe, el fd tiene que ser 1 para que muestre el resultado por pantalla
	// (4) cerramos el fd input y (5) output
	if (!pid)
	{
		argv[i] = 0;
		// si hay algún error propio de la función
		// no vale fd = 0 porque cambias el valor de la variable, pero no la del sistema 
		if (dup2(fd, 0) == -1 || close(fd) == -1 || (pip && (dup2(fds[1], 1) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)))
		{
            ft_err("error: fatal\n");
            return (1);
        }
		// tenemos que mostrar por pantalla qué argumento no hemos podido ejecutar
		execve(*argv, argv, envp);
		{
			ft_err("error: cannot execute ");
			ft_err(*argv);
            ft_err("\n");
			return (1);
		}
	}
	// en caso de que sí se haya podido hacer un fork, 
	// (1) si es un "|", guardamos el valor del fd con dup2
	// (2) cerramos el fd input y (3) output
	// (4) si es un ";", el valor del fd tiene que ser 0, que es la pantalla: al segundo le asignas el primero
	// (5) el hijo espera al padre
	if ((pip && (dup2(fds[0], fd) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)) || (!pip && dup2(0, fd) == -1) || waitpid(pid, &res, 0) == -1)
	{
		ft_err("error: fatal\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0;

	fd = dup(0);
	
	while (argv[i] && argv[++i])
	{
		argv = argv + i;
		i = 0;
        // si existe y no es pipe ni ;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			ft_cdir(argv, i);
		else
			ft_ex(argv, envp, i);
	}
	return (1);
}

// ./microshell grep e "|" cat test.txt
