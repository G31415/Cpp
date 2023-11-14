char *strcat(char *dest, const char *src)
{
    int x=0;
    while((dest[x]!=’\0’)  x++;
    while((dest[x]=*src[x])!=’\0’){ x++; }
    return dest;
}
