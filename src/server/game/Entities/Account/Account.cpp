/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Account.h"
#include "Map.h"
#include "Player.h"
#include "StringFormat.h"
#include "WorldSession.h"

namespace Battlenet
{
Account::Account(WorldSession* session, ObjectGuid guid, std::string&& name) : m_session(session), m_name(std::move(name))
{
    _Create(guid);

    m_entityFragments.Add(WowCS::EntityFragment::FHousingStorage_C, false, WowCS::FragmentSerializationTraits<&Account::m_housingStorageData>{});

    // Default value
    SetUpdateFieldValue(m_values.ModifyValue(&Account::m_housingStorageData).ModifyValue(&UF::HousingStorageData::DecorMaxOwnedCount), 5000);
}

void Account::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Account::m_housingStorageData);
    BaseEntity::ClearUpdateMask(remove);
}

std::string Account::GetNameForLocaleIdx(LocaleConstant /*locale*/) const
{
    return m_name;
}

void Account::BuildUpdate(UpdateDataMapType& data_map)
{
    BuildUpdateChangesMask();

    if (Player* owner = m_session->GetPlayer())
        BuildFieldsUpdate(owner, data_map);

    ClearUpdateMask(false);
}

std::string Account::GetDebugInfo() const
{
    return Trinity::StringFormat("{}\nName: {}", BaseEntity::GetDebugInfo(), m_name);
}

UF::UpdateFieldFlag Account::GetUpdateFieldFlagsFor(Player const* target) const
{
    if (*target->m_playerData->BnetAccount == GetGUID())
        return UF::UpdateFieldFlag::Owner;

    return UF::UpdateFieldFlag::None;
}

bool Account::AddToObjectUpdate()
{
    if (Player* owner = m_session->GetPlayer(); owner && owner->IsInWorld())
    {
        owner->GetMap()->AddUpdateObject(this);
        return true;
    }

    return false;
}

void Account::RemoveFromObjectUpdate()
{
    if (Player* owner = m_session->GetPlayer(); owner && owner->IsInWorld())
        owner->GetMap()->RemoveUpdateObject(this);
}
}
