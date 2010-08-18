/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#ifndef _CALLBACK_H
#define _CALLBACK_H

#include <ace/Future.h>
#include <ace/Future_Set.h>

#include "DatabaseEnv.h"

typedef ACE_Future<QueryResult_AutoPtr> QueryResultFuture;

/*! A simple template using ACE_Future to manage callbacks from the thread and object that
    issued the request. <ParamType> is variable type of parameter that is used as parameter
    for the callback function.
*/
template <typename ParamType>
class QueryCallback
{
    public:
        QueryCallback() {}
        
        void SetFutureResult(QueryResultFuture value)
        {
            result = value;
        }
        
        QueryResultFuture GetFutureResult()
        {
            return result;    
        }
        
        int IsReady()
        {
            return result.ready();
        }
        
        void GetResult(QueryResult_AutoPtr res)
        {
            result.get(res);
        }
        
        void FreeResult()
        {
            result.cancel();
        }
        
        void SetParam(ParamType value)
        {
            param = value;
        }
        
        ParamType GetParam()
        {
            return param;
        }
        
    private:
        QueryResultFuture result;
        ParamType param;
};

#endif