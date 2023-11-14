int max(int c, ...)
{
    int * p = &c + 1;
    int r = *p;
    for (int x= c-1; x>0; x--) {
        if (r < p[x]) r = p[x];
    }
    return r;
}


