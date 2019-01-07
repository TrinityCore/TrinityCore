/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "Log.h"

void DB2HotfixGeneratorBase::LogMissingRecord(std::string const& storageName, uint32 recordId)
{
    TC_LOG_ERROR("db2.hotfix", "Hotfix specified for %s row id %u which does not exist", storageName.c_str(), recordId);
}

void DB2HotfixGeneratorBase::AddClientHotfix(uint32 tableHash, uint32 recordId)
{
    sDB2Manager.InsertNewHotfix(tableHash, recordId);
}
