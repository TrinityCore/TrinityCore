/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "defines.h"

int main(int argc, char* argv[])
{
    char sPGhost[26], sPGport[26], sPGdb[26], sPGuser[26], sPGpass[26];
    printf("Postgres connection settings\n Host>");
    scanf("%s",sPGhost);
    printf(" Port>");
    scanf("%s",sPGport);
    printf(" Base>");
    scanf("%s",sPGdb);
    printf(" User>");
    scanf("%s",sPGuser);
    printf(" Pass>");
    scanf("%s",sPGpass);

    ///////////////////////////////
    ///////PGSQL Connect///////////
    ///////////////////////////////
    PGconn *mPGconn=NULL;
    mPGconn = PQsetdbLogin(sPGhost,sPGport, NULL, NULL, sPGdb, sPGuser, sPGpass);

    if (PQstatus(mPGconn) != CONNECTION_OK)
    {
        printf("Could not connect to Postgre database at [%s]: \n %s\n",sPGhost, PQerrorMessage(mPGconn));
        PQfinish(mPGconn);
        return 1;
    }
    else
    {
        printf("Connected to Postgre database at [%s]\n", sPGhost);
        printf(" PostgreSQL server ver: [%d]\n\n",PQserverVersion(mPGconn));
    }

    /// Set dummy notice processor
    PQsetNoticeProcessor(mPGconn, pg_notice, mPGconn);

    ///////////////////////////////
    ///////MySQL Connect///////////
    ///////////////////////////////
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        printf( "Could not initialize Mysql connection\n" );
        return 1;
    }

    char sMYhost[26], sMYdb[26], sMYuser[26], sMYpass[26];
    int    iMYport;
    printf("Mysql connection settings \n Host>");
    scanf("%s",sMYhost);
    printf(" Port>");
    scanf("%d",&iMYport);
    printf(" Base>");
    scanf("%s",sMYdb);
    printf(" User>");
    scanf("%s",sMYuser);
    printf(" Pass>");
    scanf("%s",sMYpass);

    mysql_options(mysqlInit,MYSQL_SET_CHARSET_NAME,"utf8");

    MYSQL *mMysql;
    mMysql = mysql_real_connect(mysqlInit, sMYhost, sMYuser,  sMYpass, sMYdb, iMYport, NULL, 0);

    if (mMysql)
    {
        printf( "Connected to MySQL database at [%s] \n", sMYhost);
        printf( " MySQL client library: [%s] \n", mysql_get_client_info());
        printf( " MySQL server ver: [%s] \n\n", mysql_get_server_info( mMysql));
    }
    else
    {
        printf("Could not connect to MySQL database at [%s]:\n %s\n", sMYhost ,mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return 1;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    MYSQL_FIELD *fields = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount =0;
    result = mysql_list_tables( mMysql , NULL );
    rowCount   = mysql_num_rows(result);

    /***********************/
    /* get list of tables  */
    /***********************/
    T_TableList mTableList;
    mTableList.reserve((size_t)rowCount);
    while( (row = mysql_fetch_row(result)) !=NULL )
    {
        for (uint32 i = 0;i<mysql_num_fields(result);i++)
        {
            mTableList.push_back(row[i]);
        }
    }
    mysql_free_result(result);

    /****************************************/
    /* convert filed type and default type  */
    /****************************************/
    T_Table m_Table;
    TDataBase m_DataBase_Map;
    m_DataBase_Map.clear();
    for (uint32 j=0; j<mTableList.size();++j)
    {
        result     = mysql_list_fields(mMysql, mTableList[j].c_str(), NULL);
        fieldCount = mysql_num_fields(result);
        fields     = mysql_fetch_fields(result);

        for (uint32 i=0; i<fieldCount;++i)
        {
            sField mfield;
            mfield.name   = fields[i].name;
            if (!fields[i].def)
            {
                mfield.def = "NULL";
            }
            else if (!strcmp(fields[i].def,"0000-00-00 00:00:00"))
            {
                /// Convert MySQL Default timestamp to PGSQL Default timestamp
                mfield.def.append("'1970-01-01 00:00:00'");
            }
            else
            {
                /// Append '
                mfield.def.append("'");
                mfield.def.append(fields[i].def);;
                mfield.def.append("'");
            }
            mfield.type = ConvertNativeType(fields[i].type,fields[i].length);
            mfield.flags  = fields[i].flags;
            m_Table.push_back(mfield);
        }
        m_DataBase_Map[mTableList[j]] = m_Table;
        m_Table.clear();
        mysql_free_result(result);
    }

    /******************************************/
    /* Conversion of the layout of the tables */
    /******************************************/

    uint32 count = 0;
    TDataBase::const_iterator citr;
    for (citr = m_DataBase_Map.begin(); citr != m_DataBase_Map.end(); ++citr)
    {
        ostringstream sql_str;
        sql_str<<"DROP TABLE IF EXISTS "<<(*citr).first.c_str()<<";\n";
        sql_str<<"CREATE TABLE "<<(*citr).first.c_str()<<"(\n";

        T_Table::const_iterator v_iter;
        ostringstream prim_key_str;
        ostringstream index_str;
        for (v_iter = (*citr).second.begin();
            v_iter != (*citr).second.end();
            ++v_iter)
        {
            sql_str<<" "<<(*v_iter).name;
            if (((*v_iter).flags & AUTO_INCREMENT_FLAG)!=0)
            {
                /// AUTO_INCREMENT fields not have "default" data
                sql_str<<" bigserial";
            }
            else
            {
                sql_str<<" "<<(*v_iter).type;
                sql_str<<" default "<<(*v_iter).def;
            }
            /// IF column have PRIMARY KEY flag then use column in PRIMARY KEY
            if (IS_PRI_KEY( (*v_iter).flags )!=0)
            {
                if( prim_key_str.str().size())
                    prim_key_str << ", ";
                else
                {
                    prim_key_str << "ALTER TABLE ";
                    prim_key_str << (*citr).first.c_str();
                    prim_key_str << " ADD CONSTRAINT pk_";
                    prim_key_str << (*citr).first.c_str();
                    prim_key_str << "_";
                    prim_key_str << (*v_iter).name;
                    prim_key_str << " PRIMARY KEY (";
                }
                prim_key_str<<(*v_iter).name;
            }
            else if (((*v_iter).flags & MULTIPLE_KEY_FLAG)!=0)
            {
                /// IF column have INDEX flag then create INDEX
                index_str << "CREATE INDEX  idx_";
                index_str << (*citr).first.c_str();
                index_str << "_";
                index_str << (*v_iter).name;
                index_str << " ON ";
                index_str << (*citr).first.c_str();
                index_str << " USING btree (";
                index_str << (*v_iter).name;
                index_str << ");\n";
            }
            else if (((*v_iter).flags & UNIQUE_KEY_FLAG)!=0)
            {
                /// IF column have UNIQUE INDEX flag then create INDEX
                index_str << "CREATE UNIQUE INDEX  uidx_";
                index_str << (*citr).first.c_str();
                index_str << "_";
                index_str << (*v_iter).name;
                index_str << " ON ";
                index_str << (*citr).first.c_str();
                index_str << " USING btree (";
                index_str << (*v_iter).name;
                index_str << ");\n";
            }
            /// don't output "," for last column
            if(v_iter + 1 != (*citr).second.end())
                sql_str<< ",\n";
            else
                sql_str<< "\n";
        }
        sql_str<< ")\n";

        /// Out Table structure
        PG_Exec_str(sql_str.str(),mPGconn);

        /// out PRIMARY KEY
        if(prim_key_str.str().size())
        {
            prim_key_str<<")";
            PG_Exec_str(prim_key_str.str(),mPGconn);
        }

        /// out INDEX's
        if (index_str.str().size())
            PG_Exec_str(index_str.str(),mPGconn);

        ++count;
        printf("Convert [%d] tables...\r",count);
    }
    printf("Completed the conversion of [%d] tables!\n", count);

    /****************/
    /* Copying data */
    /****************/

    count = 0;
    for (uint32 j=0; j<mTableList.size();++j)
    {
        ostringstream sql_str;
        sql_str << "SELECT * FROM ";
        sql_str << mTableList[j].c_str();

        if (mysql_query(mysqlInit,sql_str.str().c_str()) )
            continue;
        if (!(result = mysql_store_result(mysqlInit)))
            continue;

        while ((row = mysql_fetch_row(result))!=NULL)
        {
            ostringstream insert_str;
            insert_str << "INSERT INTO ";
            insert_str << mTableList[j].c_str();
            insert_str << " VALUES (";

            fieldCount = mysql_num_fields(result);
            fields     = mysql_fetch_fields(result);
            for (uint32 i = 0 ; i < fieldCount ; ++i)
            {
                if (!row[i])
                    insert_str << "NULL";
                else
                {
                    if (IsNeeedEscapeString(fields[i].type))
                    {
                        string field_str = row[i];
                        PG_Escape_Str(field_str);
                        insert_str << "E'";
                        insert_str << field_str.c_str();
                        insert_str << "'";
                    }
                    else if (!strcmp(row[i],"0000-00-00 00:00:00"))
                    {
                        /// Convert MySQL  timestamp to PGSQL timestamp
                        insert_str << "'1970-01-01 00:00:00'";
                    }
                    else
                    {
                        insert_str << "'";
                        insert_str << row[i];
                        insert_str << "'";
                    }
                }

                /// don't output "," for last column
                if(i + 1 != fieldCount )
                    insert_str<< ",";
                else
                    insert_str<< ")\n";
            }
            PG_Exec_str(insert_str.str(), mPGconn);
        }
        mysql_free_result(result);
        ++count;
        printf("Copied data from [%d] tables...\r",count);
    }
    printf("Finished copying the data from [%d] tables!\n",count);
    mTableList.clear();
    m_DataBase_Map.clear();

    /// Close connections
    mysql_close(mMysql);
    PQfinish(mPGconn);

    printf("end\n");
    return 0;

}

