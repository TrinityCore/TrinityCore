/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DBCSFRM_H
#define TRINITY_DBCSFRM_H

// x - skip<uint32>, X - skip<uint8>, s - char*, f - float, i - uint32, b - uint8, d - index (not included)
// n - index (included), l - uint64, p - field present in sql dbc, a - field absent in sql dbc

char const BannedAddOnsfmt[] = "nxxxxxxxxxx";
char const BattlemasterListfmt[] = "niiiiiiiiiiiiiiiiixsiiiixxxxxxx";
char const CharSectionsfmt[] = "diiixxxiii";
char const ChrClassesfmt[] = "nixsxxxixiiiiixxxxx";
char const CreatureModelDatafmt[] = "niixxxxxxxxxxxxxxffxxxxxxxxxxxxxxxxx";
char const EmotesTextSoundEntryfmt[] = "niiii";
char const Factionfmt[] = "niiiiiiiiiiiiiiiiiiffixsxixx";
char const FactionTemplatefmt[] = "niiiiiiiiiiiii";
char const LFGDungeonfmt[] = "nsiiixxiiiixxixixxxxxxxxxxxxxx";
char const Lightfmt[] = "nifffxxxxxxxxxx";
char const LiquidTypefmt[] = "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char const MapDifficultyfmt[] = "diisiiii";
char const SpellItemEnchantmentfmt[] = "niiiiiiiiiixiiiiiiiiiifffxxx";
char const Talentfmt[] = "niiiiiiiiix";
char const Vehiclefmt[] = "niiffffiiiiiiiifffffffffffffffxxxxfifiiii";
char const WMOAreaTablefmt[] = "niiixxxxxiixxxx";
char const WorldMapAreafmt[] = "xinxffffixxxxx";
char const WorldSafeLocsfmt[] = "niffffx";

#endif
