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

#ifndef TRINITYCORE_ACCOUNT_H
#define TRINITYCORE_ACCOUNT_H

#include "BaseEntity.h"

class WorldSession;

namespace Battlenet
{
class Account final : public BaseEntity
{
public:
    explicit Account(WorldSession* session, ObjectGuid guid, std::string&& name);

    void ClearUpdateMask(bool remove) override;

    std::string GetNameForLocaleIdx(LocaleConstant locale) const override;

    void BuildUpdate(UpdateDataMapType& data_map) override;

    std::string GetDebugInfo() const override;

    UF::UpdateField<UF::HousingStorageData, int32(WowCS::EntityFragment::FHousingStorage_C), 0> m_housingStorageData;

protected:
    UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const override;

    bool AddToObjectUpdate() override;
    void RemoveFromObjectUpdate() override;

private:
    WorldSession* m_session;
    std::string m_name;
};
}

#endif // TRINITYCORE_ACCOUNT_H
