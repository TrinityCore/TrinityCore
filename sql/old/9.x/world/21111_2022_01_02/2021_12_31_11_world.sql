-- Convert char to varchar
ALTER TABLE `areatrigger_scripts` MODIFY `ScriptName` varchar(64) NOT NULL;
ALTER TABLE `battleground_template` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `battleground_template` MODIFY `Comment` varchar(32) NOT NULL;
ALTER TABLE `conditions` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `creature` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `criteria_data` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `game_weather` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `gameobject` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `gameobject_template` MODIFY `AIName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `outdoorpvp_template` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `spell_script_names` MODIFY `ScriptName` varchar(64) NOT NULL;
ALTER TABLE `transports` MODIFY `ScriptName` varchar(64) NOT NULL DEFAULT '';

-- floats
ALTER TABLE `creature_formations` MODIFY `dist` float NOT NULL;
ALTER TABLE `creature_formations` MODIFY `angle` float NOT NULL;
ALTER TABLE `creature_text` MODIFY `Probability` float NOT NULL DEFAULT '0';
ALTER TABLE `item_template_addon` MODIFY `SpellPPMChance` float NOT NULL DEFAULT '0';
ALTER TABLE `player_xp_for_level` MODIFY `Experience` int(10) unsigned NOT NULL;
ALTER TABLE `pool_members` MODIFY `chance` float NOT NULL;
ALTER TABLE `script_spline_chain_meta` MODIFY `velocity` float NOT NULL DEFAULT '0';

-- longtext
ALTER TABLE `command` MODIFY `help` mediumtext NOT NULL;
ALTER TABLE `creature_text` MODIFY `Text` mediumtext NOT NULL;
ALTER TABLE `page_text` MODIFY `Text` mediumtext NOT NULL;
