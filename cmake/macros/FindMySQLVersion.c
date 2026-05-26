#include <mysql.h>
#include <stdio.h>

int main()
{
    printf("{ "
        "\"version\": \"%d.%d.%d\", "
        "\"flavor\": \"%s\""
        " }",
        MYSQL_VERSION_ID / 10000, (MYSQL_VERSION_ID / 100) % 100, MYSQL_VERSION_ID % 100,
#ifdef MARIADB_VERSION_ID
        "MariaDB"
#else
        "MySQL"
#endif
        );
    return 0;
}
