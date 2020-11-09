#include <stdlib.h>
#include <stdio.h>

int	ft_is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int i;
	int words;

	i = 0;
	words = 0;

	while (str[i])
	{
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_charset(str[i], charset) && str[i])
			words++;
		while (!ft_is_charset(str[i], charset) && str[i])
			i++;
	}
	return (words);
}


char	*make_str(char *str, int count, char *charset)
{
	int i;
	int j;
	char *result;
	
	i = count;
	j = 0;
	while (!ft_is_charset(str[i], charset) && str[i])
	{
		j++;
		i++;
	}
	if(!(result = malloc((j + 1) * sizeof(char))))
		return (0);
	i = count;
	j = 0;
	while (!ft_is_charset(str[i], charset) && str[i])
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] =  '\0';
	return (result);
	
}

char	**ft_split(char *str, char *charset)
{
	char **tab;
	int words;
	int i;
	int j;

	words = count_words(str, charset);
	if(!(tab = malloc((words + 1) * sizeof(char*))))
		return (0);
	tab[words] = 0;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_charset(str[i], charset) && str[i])
		{
			tab[j] = make_str(str, i, charset);
			printf("tab[%d] = %s \n", j, tab[j]);
			j++;
			i++;
		}
		while (!ft_is_charset(str[i], charset) && str[i])
			i++;
	}
	return (tab);
}


int	main()
{
	char **tab;
	int words;
	int i;
	char str[] = "dgfddjdg01AZTERREYT*/1bcvvxbx/*12";
	char charset[] = "012/*";
	
	words = count_words(str, charset);
	tab = ft_split(str, charset);

	i = 0;
	printf("***********MAIN*******\n");
	while (i < words)
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}

	i = 0;
	while (i < words)
	{
		free(tab[i]);
		i++;
	}
	free(tab);

}
