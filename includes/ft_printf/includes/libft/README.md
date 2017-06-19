# libft


## char **ft_strsplit(char const *s, char c);
    Allocates and returns an array of “fresh” strings (all ending with ’\0’, including the array itself) obtained by
    spliting s using the character c as a delimiter. If the allocation fails the function returns NULL. 
    
    Example: 
        ft_strsplit("*hello*fellow***students*", ’*’) returns the array ["hello", "fellow", "students"].
             
## char *ft_itoa(int nb);
    Allocate and returns a “fresh” string ending with ’\0’ representing the integer nb given as argument. Negative
    numbers must be supported. If the allocation fails, the function returns NULL.

## char *ft_itoabase(unsigned int nb, char *base);
    Allocate and returns a “fresh” string ending with ’\0’ representing the integer nb given as argument in the base 
    given by the second argument formated as string. Negative numbers must be supported. If the allocation fails, the 
    function returns NULL.

## char *ft_strcat(char *s1, const char *s2);
    appends the s2 string to the s1 string, overwriting the terminating null byte ('\0') at the end of dest, and then
    adds a terminating null byte. The strings may not overlap, and the dest string must have enough space for the
    result. If dest is not large enough, program behavior is unpredictable.

## char *ft_strchr(const char *s, int c);
    returns a pointer to the first occurrence of the character c in the string s or NULL.

## char *ft_strcpy(char *dest, const char *src);
    copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest.
    The strings may not overlap, and the destination string dest must be large enough to receive the copy.

## char *ft_strdup(char *src);
    returns a pointer to a new string which is a duplicate of the string s.

## char *ft_strjoin(char const *s1, char const *s2);
    Allocates and returns a “fresh” string ending with ’\0’, result of the concatenation of s1 and s2. If the allocation
    fails the function returns NULL.

## char *ft_strjoinfree(char **s1, char **s2, int which);
    Allocates and returns a “fresh” string ending with ’\0’, result of the concatenation of s1 and s2. If the allocation
    fails the function returns NULL. String(s) selected with which is/are freed.

## char *ft_strmap(char const *s, char (*f)(char));
    Applies the function f to each character of the string given as argument to create a “fresh” new string resulting
    from the successive applications of f.

## char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
    Applies the function f to each character of the string passed as argument by giving its index as first argument to
    create a “fresh” new string resulting from the successive applications of f.

## char *ft_strncat(char *s1, const char *s2, size_t n);
    appends the s2 string to the s1 string, overwriting the terminating null byte ('\0') at the end of s1, and then
    adds a terminating null byte. The strings may not overlap, and the dest s1 must have enough space for the result.
    If dest is not large enough, program behavior is unpredictable

## char *ft_strncpy(char *dest, const char *src, size_t len);
    copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest.
    The strings may not overlap, and the destination string dest must be large enough to receive the copy.

## char *ft_strnew(size_t size);
    Allocates and returns a “fresh” string ending with ’\0’. Each character of the string is initialized at ’\0’.
    If the allocation fails the function returns NULL.

## char *ft_strrchr(const char *s, int c);
    returns a pointer to the last occurrence of the character c in the string s.

## char *ft_strrealloc(char *str, int size);
    Allocates and returns a “fresh” string wich is a copy of str with size more allocated space.

## char *ft_strstr(const char *big, const char *little);
    locates the first occurrence of the null-terminated string little in the null-terminated string big.

## char *ft_strnstr(const char *s1, const char *s2, size_t n);
    locates the first occurrence of the null-terminated string s2 in the string s1, where not more than n characters
    are searched.	Characters that appear after a '\0' character are not searched.

## char *ft_strsub(char const *s, unsigned int start, size_t len);
    Allocates and returns a “fresh” substring from the string given as argument. The substring begins at indexstart
    and is of size len. If start and len aren’t refering to a valid substring, the behavior is undefined. If the
    allocation fails, the function returns NULL

## char *ft_strtrim(char const *s);
    Allocates and returns a copy of the string given as argument without whitespaces at the beginning or at the end of
    the string. Will be considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
    at the beginning or at the end, the function returns a copy of s. If the allocation fails the function returns NULL.

## int ft_atoi(char *str);
    Converts the initial portion of the string pointed to by nptr to int.

## int ft_isalnum(int i);
    checks for an alphanumeric character.

## int ft_isalpha(int i);
    checks for an alphabetic character

## int ft_isascii(int i);
    checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.

## int ft_isdigit(int i);
    checks for a digit (0 through 9).

## int ft_isprint(int i);
    checks for any printable character including space.

## int ft_lstlen(t_list *lst);
    return the node quatity of lst.

## int ft_memcmp(const void *s1, const void *s2, size_t len);
    compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.

## int ft_strcmp(char *s1, char *s2);
    compares the two strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found,
    respectively, to be less than, to match, or be greater than s2.

## int ft_strncmp(const char *s1, const char *s2, size_t n);
    is similar, except it only compares the first (at most) n bytes of s1 and s2.

## int ft_strequ(char const *s1, char const *s2);
    Lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.

## int ft_strlen(char *str);
    return the number of chars composing str.

## int ft_strnequ(char const *s1, char const *s2, size_t n);
    Lexicographical comparison between s1 and s2 up to n characters or until a ’\0’ is reached. If the 2 strings are
    identical, the function returns 1, or 0 otherwise.

## int ft_tolower(int i);
    converts the letter i to lower case, if possible.

## int ft_toupper(int i);
    converts the letter i to upper case, if possible.

## size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
    appends a maximum of (dstsize-strlen(dst)-1) characters of src to dst (where dstsize represents the size of the
    string buffer dst). If the string pointed to by dst contains a nullterminated string that fits into dstsize bytes
    when strlcat() is called, the string pointed to by dst is a null-terminated string that fits in dstsize bytes
    (including the terminating null character) when it completes, and the initial character of src overrides the null
    character at the end of dst. If the string pointed to by dst is longer than dstsize bytes when strlcat() is called,
    the string pointed to by dst is not changed. The function returns min{dstsize, strlen(dst)}+strlen(src).

## t_list *ft_lstgoto(t_list *lst, int place);
    return a pointer to the place position in the lst list.

## t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
    Iterates a list lst and applies the function f to each link to create a “fresh” list (using malloc(3)) resulting
    from the successive applications of f. If the allocation fails, the function returns NULL.

## t_list *ft_lstnew(void const *content, size_t content_size);
    Allocates and returns a “fresh” link. The variables content and content_size of the new link are initialized by
    copy of the parameters of the function. If the parameter content is nul, the variable content is initialized to
    NULL and the variable content_size is initialized to 0 even if the parameter content_size isn’t. The variable next
    is initialized to NULL. If the allocation fails, the function returns NULL.

## void *ft_memalloc(size_t size);
    Allocates and returns a “fresh” memory area. The memory allocated is initialized to 0. If the allocation fails,
    the function returns NULL.

## void *ft_memccpy(void *dst, const void *src, int c, size_t n);
    Copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found.

## void *ft_memchr(const void *s, int c, size_t n);
    scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes
    of the memory area pointed to by s are interpreted as unsigned char.

## void *ft_memcpy(void *dst, const void *src, size_t n);
    Copies no more than n bytes from memory area src to memory area dest.

## void *ft_memmove(void *dst, const void *src, size_t len);
    copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as
    though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes
    are then copied from the temporary array to dest.

## void *ft_memset(void *s, int c, size_t n);
    fills the first n bytes of the memory area pointed to by s with the constant byte c.

## void ft_bzero(void *s, size_t n);
    sets the first n bytes of the area starting at s to zero.

## void ft_lstadd(t_list **alst, t_list *new);
    Adds the element new at the beginnning of the list.

## void ft_lstaddend(t_list **alst, t_list *new);
    Adds the element new at the ending of the list.

## void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
    Takes as a parameter the adress of a pointer to a link and frees the memory of this link and every successors
    of that link using the functions del and free(3). Finally the pointer to the link that was just freed must be
    set to NULL (quite similar to the function ft_memdel from the mandatory part).

## void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
    Takes as a parameter a link’s pointer address and frees the memory of the link’s content using the function del
    given as a parameter, then frees the link’s memory using free(3). The memory of next musnt not be freed under
    any circumstance. Finally, the pointer to the link that was just freed must be set to NULL (quite similar to
    the function ft_memdel in the mandatory part).

## void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
    Iterates the list lst and applies the function f to each link.

## void ft_lstreplace(t_list **lst, t_list *new, int place);
    replace the node in the place position of the lst list by the new node.

## void ft_memdel(void **ap);
    n Takes as a parameter the address of a memory area that needs to be freed, then puts the pointer to NULL.

## void ft_putchar(char c);
    Description Outputs the character c to the standard output.

## void ft_putchar_fd(char c, int fd);
    Description Outputs the character c to the fd file descriptor.

## void ft_putendl(char const *s);
    Outputs the string s to the standard output followed by a ’\n’.

## void ft_putendl_fd(char const *s, int fd);
    Outputs the string s to the fd file descriptor followed by a ’\n’.

## void ft_putnbr(int n);
    Outputs the integer n to the standard output.

## void ft_putnbr_fd(int n, int fd);
    Outputs the integer n to the fd file descriptor.

## void ft_putnbrbase(unsigned int n, char *base);
    Outputs the integer n to the standard output in the chosen base.

## void ft_putstr(char const *str);
    Outputs the string s to the standard output.

## void ft_putstr_fd(char const *str, int fd);
    Outputs the string s to the fd file descriptor.

## void ft_strclr(char *s);
    Sets every character of the string to the value ’\0’.

## void ft_strdel(char **as);
    Takes as a parameter the address of a string that need to be freed, then sets its pointer to NULL.

## void ft_striter(char *s, void (*f)(char *));
    Applies the function f to each character of the string passed as argument. Each character is passed by
    address to f to be modified if necessary

## void ft_striteri(char *s, void (*f)(unsigned int, char *));
    Applies the function f to each character of the string passed as argument, and passing its index as first
    argument. Each character is passed by address to f to be modified if necessary

