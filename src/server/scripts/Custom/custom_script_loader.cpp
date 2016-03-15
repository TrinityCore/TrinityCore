/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
void AddSC_Boss_SlaveWatcherCrushto();
void AddSC_Boss_Roltall();
void AddSC_Boss_Gugrokk();
void AddSC_Boss_Magmolatus();

void AddSC_boss_fleshrender_nokgar();
void AddSC_boss_ahriok_dugru();
void AddSC_boss_oshir();
void AddSC_boss_skulloc();

void AddSC_boss_vigilant_kaathar();
void AddSC_boss_soulbinder_nyami();
void AddSC_boss_azzakel();
void AddSC_boss_terongor();

void AddSC_boss_ranjit();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
		/* MINAS MACHACASANGRE */
	AddSC_Boss_SlaveWatcherCrushto();
	AddSC_Boss_Roltall();
	AddSC_Boss_Gugrokk();
	AddSC_Boss_Magmolatus();

	/* PUERTO DE HIERRO */
	AddSC_boss_fleshrender_nokgar();
	AddSC_boss_ahriok_dugru();
	AddSC_boss_oshir();
	AddSC_boss_skulloc();

	/* AUCHINDOUN */
	AddSC_boss_vigilant_kaathar();
	AddSC_boss_soulbinder_nyami();
	AddSC_boss_azzakel();
	AddSC_boss_terongor();

	/* TRECHO CELESTIAL */
	AddSC_boss_ranjit();
}
