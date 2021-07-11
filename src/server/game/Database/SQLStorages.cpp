/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#include "SQLStorages.h"
#include "Database/SQLStorage.h"
#include "Database/SQLStorageImpl.h"
#include "Database/DatabaseEnv.h"

char const CreatureInfosrcfmt[] = "iiiiiffffiiiiiissiiiiiiiiiifffffifffiifiiiiiiiiiiffiiiiiiiiiiiiiiiiiisiisiiiliiiiiiis";
char const CreatureInfodstfmt[] = "iiiiiffffiiiiiissiiiiiiiiiifffffifffiifiiiiiiiiiiffiiiiiiiiiiiiiiiiiisiisiiiliiiiiiii";
char const CreatureDataAddonInfofmt[] = "iiiibbis";
char const CreatureDisplayInfoAddonfmt[] = "iffbi";
char const GameObjectDisplayInfoAddonfmt[] = "iffffff";
char const EquipmentInfofmt[] = "iiii";
char const GameObjectInfosrcfmt[] = "iiisiifiiiiiiiiiiiiiiiiiiiiiiiiiis";
char const GameObjectInfodstfmt[] = "iiisiifiiiiiiiiiiiiiiiiiiiiiiiiiii";
char const ItemPrototypesrcfmt[] = "iiissiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiififfiffiffiffiffiiiiiiiiiiiifiiiiiifiiiiiifiiiiiifiiiiiifiiiiiiiiiiiiiiiiiiiiiiii";
char const ItemPrototypedstfmt[] = "iiissiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiififfiffiffiffiffiiiiiiiiiiiifiiiiiifiiiiiifiiiiiifiiiiiifiiiiiiiiiiiiiiiiiiiiiiiix";
char const PageTextfmt[] = "isi";
char const MapEntrysrcfmt[] = "iiiiiiiffss";
char const MapEntrydstfmt[] = "iiiiiiiffsi";
char const ConditionsSrcFmt[] = "iiiiiii";
char const ConditionsDstFmt[] = "iiiiiii";
char const AreaEntryfmt[] = "iiiiiisii";
char const MailTemplatefmt[] = "issssssss";
char const CreatureSpellDatafmt[] = "iiiii";

SQLStorage sCreatureStorage(CreatureInfosrcfmt, CreatureInfodstfmt, "entry", "creature_template");
SQLStorage sCreatureDataAddonStorage(CreatureDataAddonInfofmt, "guid", "creature_addon");
SQLStorage sCreatureDisplayInfoAddonStorage(CreatureDisplayInfoAddonfmt, "display_id", "creature_display_info_addon");
SQLStorage sGameObjectDisplayInfoAddonStorage(GameObjectDisplayInfoAddonfmt, "display_id", "gameobject_display_info_addon");
SQLStorage sEquipmentStorage(EquipmentInfofmt, "entry", "creature_equip_template");
SQLStorage sItemStorage(ItemPrototypesrcfmt, ItemPrototypedstfmt, "entry", "item_template");
SQLStorage sPageTextStore(PageTextfmt, "entry", "page_text");
SQLStorage sMapStorage(MapEntrysrcfmt, MapEntrydstfmt, "entry", "map_template");
SQLStorage sConditionStorage(ConditionsSrcFmt, ConditionsDstFmt, "condition_entry", "conditions");
SQLStorage sAreaStorage(AreaEntryfmt, "entry", "area_template");
SQLStorage sMailTemplateStorage(MailTemplatefmt, "entry", "mail_text_template");
SQLStorage sCreatureSpellDataStorage(CreatureSpellDatafmt, "entry", "pet_spell_data");

SQLHashStorage sGOStorage(GameObjectInfosrcfmt, GameObjectInfodstfmt, "entry", "gameobject_template");