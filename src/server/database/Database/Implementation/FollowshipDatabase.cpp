/*
 * This file is part of the Stefal WoW Project.
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
 */

#include "FollowshipDatabase.h"
#include "MySQLPreparedStatement.h"

void FollowshipDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_FOLLOWSHIPDATABASE_STATEMENTS);

    PrepareStatement(FSB_SEL_BOT_OWNERS_ALL,
        "SELECT bot_id, bot_guid, bot_entry, player_guid, hire_expiry_time FROM bot_owners", CONNECTION_SYNCH);

    PrepareStatement(FSB_SEL_BOT_OWNERS_BY_PLAYER,
        "SELECT bot_id, bot_guid, bot_entry, hire_expiry_time FROM bot_owners WHERE player_guid = ?", CONNECTION_SYNCH);

    PrepareStatement(FSB_SEL_BOT_OWNER_ID,
        "SELECT bot_id FROM bot_owners WHERE bot_guid = ? AND player_guid = ?", CONNECTION_SYNCH);

    PrepareStatement(FSB_INS_BOT_OWNER,
        "INSERT INTO bot_owners (bot_guid, bot_entry, player_guid, hire_expiry_time) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);

    PrepareStatement(FSB_DEL_BOT_OWNER_BY_GUID,
        "DELETE FROM bot_owners WHERE bot_guid = ?", CONNECTION_ASYNC);

    PrepareStatement(FSB_DEL_BOT_OWNER_BY_ENTRY_PLAYER,
        "DELETE FROM bot_owners WHERE bot_entry = ? AND player_guid = ?", CONNECTION_ASYNC);

    PrepareStatement(FSB_SEL_BOT_TEMPLATES_ALL,
        "SELECT entry, bot_class, bot_race, companion_spell, chatter_type, gender, pet_source FROM bot_templates", CONNECTION_SYNCH);

    PrepareStatement(FSB_INS_BOT_TEMPLATE,
        "INSERT INTO bot_templates (entry, bot_class, bot_race, companion_spell, chatter_type, gender, pet_source) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    PrepareStatement(FSB_DEL_BOT_TEMPLATE,
        "DELETE FROM bot_templates WHERE entry = ?", CONNECTION_ASYNC);

    PrepareStatement(FSB_SEL_BOT_CHATTER_ALL,
        "SELECT id, zoneId, fsbRaceId, fsbClassId, category, chatter_type, line_text FROM bot_chatter_lines", CONNECTION_SYNCH);

    PrepareStatement(FSB_SEL_BOT_SPELLS_ALL,
        "SELECT id, spell_id, allowed_race, allowed_class, spell_type, power_cost_override, "
        "hp_threshold, spell_range, is_self_cast, is_location_target, cooldown_override, role_mask, comment FROM bot_spells", CONNECTION_SYNCH);
}

FollowshipDatabaseConnection::FollowshipDatabaseConnection(MySQLConnectionInfo& connInfo, ConnectionFlags connectionFlags)
    : MySQLConnection(connInfo, connectionFlags)
{
}

FollowshipDatabaseConnection::~FollowshipDatabaseConnection()
{
}
