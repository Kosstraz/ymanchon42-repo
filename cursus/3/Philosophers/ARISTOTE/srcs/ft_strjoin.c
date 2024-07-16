#include "Aristote.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		size1;
	int		size2;
	int		i;
	int		n;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (NULL);
	size1 = ft_strlenc(s1, '\0');
	size2 = ft_strlenc(s2, '\0');
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i])
		ret[n++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[n++] = s2[i++];
	ret[n] = '\0';
	return (ret);
}
