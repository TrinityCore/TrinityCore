/*
 * Copyright (C) 2022 BfaCore Reforged
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

 // This is where scripts' loading functions should be declared:

void AddSC_the_brawlers_guild();
void AddSC_the_brawlers_guild_bosses_rank_one();
void AddSC_the_brawlers_guild_bosses_rank_two();
void AddSC_the_brawlers_guild_bosses_rank_three();
void AddSC_the_brawlers_guild_bosses_rank_four();
void AddSC_the_brawlers_guild_bosses_rank_five();
void AddSC_the_brawlers_guild_bosses_rank_six();
void AddSC_the_brawlers_guild_bosses_rank_seven();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddBrawlersGuildScripts()
{
    // Brawlers
	AddSC_the_brawlers_guild();
	AddSC_the_brawlers_guild_bosses_rank_one();
	AddSC_the_brawlers_guild_bosses_rank_two();
	AddSC_the_brawlers_guild_bosses_rank_three();
	AddSC_the_brawlers_guild_bosses_rank_four();
	AddSC_the_brawlers_guild_bosses_rank_five();
	AddSC_the_brawlers_guild_bosses_rank_six();
	AddSC_the_brawlers_guild_bosses_rank_seven();
}
