/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include "ProgressBar.h"

char const* const barGoLink::empty = " ";
char const* const barGoLink::full  = "*";

barGoLink::barGoLink( uint64 row_count )
{
    rec_no    = 0;
    rec_pos   = 0;
    indic_len = 50;
    num_rec   = row_count;
    printf( "[" );
    for (uint64 i = 0; i < indic_len; ++i) printf( empty );
    printf( "] 0%%\r[" );
    fflush(stdout);
}

void barGoLink::step( void )
{
    uint64 i, n;

    if ( num_rec == 0 ) return;
    ++rec_no;
    n = rec_no * indic_len / num_rec;
    if ( n != rec_pos )
    {
        printf( "\r[" );
        for (i = 0; i < n; i++ ) printf( full );
        for (; i < indic_len; i++ ) printf( empty );
        float percent = (((float)n/(float)indic_len)*100);
        printf( "] %i%%  \r[", (int)percent);
        fflush(stdout);

        rec_pos = n;
    }
    
    if( num_rec == rec_no)
    {
        printf( "\n" );
        fflush(stdout);
    }
}

