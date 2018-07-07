-- remove inspector laine and investigators as they are summoned
SET @NPC_INPECTOR_LANE_GUID                           := 303006;
SET @NPC_INVESTIGATOR_1                               := 303004;
SET @NPC_INVESTIGATOR_2                               := 303007;

DELETE FROM `creature`
WHERE `guid` IN (@NPC_INPECTOR_LANE_GUID,@NPC_INVESTIGATOR_1,@NPC_INVESTIGATOR_2);

-- place the spellbunny so we can cast http://www.wowhead.com/spell=79262/summon-lous-house
SET @GO_SPELLFOCUS_ENTRY                    := 301065;
SET @GO_SPELLFOCUS_GUID                     := 7035923;

DELETE FROM `gameobject` WHERE `guid` = @GO_SPELLFOCUS_GUID AND `id` = @GO_SPELLFOCUS_ENTRY;
INSERT INTO `gameobject`
    (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`)
VALUES
    (@GO_SPELLFOCUS_GUID, @GO_SPELLFOCUS_ENTRY, 0, 0, 0, 1, 0, 0, 0, -9843.38, 1391.25, 38.1249, 0.541516, -0, -0, -0.267462, -0.963569, 300, 255, 1, 0, '', 0);
	
-- add detect invisibility 1 spell to area so that 2 shoed lou is not visible too early
DELETE FROM `spell_area` WHERE `spell` = 79229 AND `area` = 109;
INSERT INTO `spell_area`
    (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `teamId`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`)
VALUES
    (79229, 109, 26213, 0, 0, -1, 0, 2, 3, 64, 0),
    (79229, 109, 26214, 0, 0, -1, 0, 2, 3, 64, 0);	

-- update the quest position to place it at the end of the mine instead of an unreachable area	
UPDATE `quest_poi_points`
SET `X` = -9843,
`Y` = 1391
WHERE `QuestID` = 26228
AND `Idx1` = 1;
