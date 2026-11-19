-- Update a typo in original data entry
UPDATE `npc_spellclick_spells` SET `quest_end`=11999 WHERE `npc_entry`=26477 AND `spell_id`=61832 AND `quest_start`=11999;

-- Delete redundant data with invalid condition type
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18;

-- Static Data
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,
`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(18,24752,44363,0,8,0,11460,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,24752,44363,0,9,0,11460,0,0,0,'Required quest active for spellclick'),
(18,25596,45875,0,8,0,11690,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,25596,45875,0,9,0,11690,0,0,0,'Required quest active for spellclick'),
(18,25841,46166,0,8,0,11795,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,25841,46166,0,9,0,11795,0,0,0,'Required quest active for spellclick'),
(18,26200,39996,0,8,0,11960,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26200,39996,0,9,0,11960,0,0,0,'Required quest active for spellclick'),
(18,26200,61286,0,8,0,11960,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26200,61286,0,9,0,11960,0,0,0,'Required quest active for spellclick'),
(18,26421,47575,0,8,0,12092,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26421,47575,0,8,0,12096,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26421,47575,0,9,0,12092,0,0,0,'Required quest active for spellclick'),
(18,26421,47575,0,9,0,12096,0,0,0,'Required quest active for spellclick'),
(18,26477,47096,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,47096,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,47096,0,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,47096,0,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,26477,61286,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61286,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61286,0,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,61286,0,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,26477,61832,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61832,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61832,0,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,61832,0,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,27061,47920,0,8,0,12050,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,27061,47920,0,9,0,12050,0,0,0,'Required quest active for spellclick'),
(18,27354,60944,18,8,0,12244,0,0,0,'Required quest rewarded for spellclick'),
(18,27354,60944,18,9,0,12244,0,0,0,'Required quest active for spellclick'),
(18,28161,39996,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,39996,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,39996,0,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,39996,0,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,28161,51037,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51037,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51037,0,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,51037,0,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,28161,51961,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51961,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51961,0,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,51961,0,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,28162,39996,0,8,0,12519,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28162,39996,0,9,0,12519,0,0,0,'Required quest active for spellclick'),
(18,28162,50737,0,8,0,12519,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28162,50737,0,9,0,12519,0,0,0,'Required quest active for spellclick'),
(18,28162,51026,0,8,0,12519,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28162,51026,0,9,0,12519,0,0,0,'Required quest active for spellclick'),
(18,28162,61286,0,8,0,12519,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28162,61286,0,9,0,12519,0,0,0,'Required quest active for spellclick'),
(18,28202,50926,0,8,0,12527,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28202,50926,0,9,0,12527,0,0,0,'Required quest active for spellclick'),
(18,28202,50927,0,8,0,12527,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28202,50927,0,9,0,12527,0,0,0,'Required quest active for spellclick'),
(18,28203,50918,0,8,0,12527,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28203,50918,0,9,0,12527,0,0,0,'Required quest active for spellclick'),
(18,28203,50919,0,8,0,12527,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28203,50919,0,9,0,12527,0,0,0,'Required quest active for spellclick'),
(18,28222,52082,0,8,0,12546,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28222,52082,0,9,0,12546,0,0,0,'Required quest active for spellclick'),
(18,28379,51658,0,8,0,12607,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28379,51658,0,9,0,12607,0,0,0,'Required quest active for spellclick'),
(18,28389,51592,0,8,0,12605,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28389,51592,0,9,0,12605,0,0,0,'Required quest active for spellclick'),
(18,28389,51593,0,8,0,12605,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28389,51593,0,9,0,12605,0,0,0,'Required quest active for spellclick'),
(18,28782,52280,0,8,0,12687,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28782,52280,0,9,0,12687,0,0,0,'Required quest active for spellclick'),
(18,29488,54568,15,8,0,12670,0,0,0,'Required quest rewarded for spellclick'),
(18,29488,54568,15,9,0,12670,0,0,0,'Required quest active for spellclick'),
(18,29563,56795,0,8,0,1,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29598,54768,0,8,0,12856,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29708,55028,0,8,0,12856,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29708,55028,0,9,0,12856,0,0,0,'Required quest active for spellclick'),
(18,29856,55363,0,8,0,12629,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29856,55363,0,8,0,12643,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29856,55363,0,9,0,12629,0,0,0,'Required quest active for spellclick'),
(18,29856,55363,0,9,0,12643,0,0,0,'Required quest active for spellclick'),
(18,29857,55457,0,8,0,12910,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29857,55457,0,9,0,12910,0,0,0,'Required quest active for spellclick'),
(18,30066,43977,0,8,0,12953,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,30337,43671,0,8,0,13069,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,30337,43671,0,9,0,13069,0,0,0,'Required quest active for spellclick'),
(18,30500,56679,0,8,0,13045,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,30500,56679,0,9,0,13045,0,0,0,'Required quest active for spellclick'),
(18,30560,57347,0,1,0,57348,0,0,1,'Forbidden aura for spellclick'),
(18,31736,59592,0,8,0,13280,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,31736,59592,0,9,0,13280,0,0,0,'Required quest active for spellclick'),
(18,31785,59656,0,8,0,13283,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,31785,59656,0,9,0,13283,0,0,0,'Required quest active for spellclick'),
(18,31883,60123,0,1,0,48085,0,0,1,'Forbidden aura for spellclick'),
(18,31893,60123,0,1,0,48084,0,0,1,'Forbidden aura for spellclick'),
(18,31894,60123,0,1,0,28276,0,0,1,'Forbidden aura for spellclick'),
(18,31895,60123,0,1,0,27874,0,0,1,'Forbidden aura for spellclick'),
(18,31896,60123,0,1,0,27873,0,0,1,'Forbidden aura for spellclick'),
(18,31897,60123,0,1,0,7001,0,0,1,'Forbidden aura for spellclick'),
(18,32788,57539,17,8,0,13075,0,0,0,'Required quest rewarded for spellclick'),
(18,32788,57539,17,9,0,13075,0,0,0,'Required quest active for spellclick'),
(18,32790,57654,16,8,0,13073,0,0,0,'Required quest rewarded for spellclick'),
(18,32790,57654,16,9,0,13073,0,0,0,'Required quest active for spellclick'),
(18,33498,63126,0,8,0,13654,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,33498,63126,0,9,0,13654,0,0,0,'Required quest active for spellclick'),
(18,33790,62781,0,8,0,13690,0,0,0,'Required quest rewarded for spellclick'),
(18,33790,62781,0,8,0,13705,0,0,0,'Required quest rewarded for spellclick'),
(18,33791,62786,0,8,0,13696,0,0,0,'Required quest rewarded for spellclick'),
(18,33791,62786,0,8,0,13711,0,0,0,'Required quest rewarded for spellclick'),
(18,33792,62785,0,8,0,13694,0,0,0,'Required quest rewarded for spellclick'),
(18,33792,62785,0,8,0,13709,0,0,0,'Required quest rewarded for spellclick'),
(18,33793,62780,0,8,0,13688,0,0,0,'Required quest rewarded for spellclick'),
(18,33793,62780,0,8,0,13704,0,0,0,'Required quest rewarded for spellclick'),
(18,33794,62782,0,8,0,13689,0,0,0,'Required quest rewarded for spellclick'),
(18,33794,62782,0,8,0,13706,0,0,0,'Required quest rewarded for spellclick'),
(18,33795,62779,0,8,0,13685,0,0,0,'Required quest rewarded for spellclick'),
(18,33795,62779,0,8,0,13703,0,0,0,'Required quest rewarded for spellclick'),
(18,33796,62784,0,8,0,13693,0,0,0,'Required quest rewarded for spellclick'),
(18,33796,62784,0,8,0,13708,0,0,0,'Required quest rewarded for spellclick'),
(18,33798,62787,0,8,0,13695,0,0,0,'Required quest rewarded for spellclick'),
(18,33798,62787,0,8,0,13710,0,0,0,'Required quest rewarded for spellclick'),
(18,33799,62783,0,8,0,13691,0,0,0,'Required quest rewarded for spellclick'),
(18,33799,62783,0,8,0,13707,0,0,0,'Required quest rewarded for spellclick'),
(18,33800,62774,0,8,0,13593,0,0,0,'Required quest rewarded for spellclick'),
(18,33800,62774,0,8,0,13684,0,0,0,'Required quest rewarded for spellclick'),
(18,33842,63791,0,8,0,13668,0,0,0,'Required quest rewarded for spellclick'),
(18,33842,63791,0,8,0,13687,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,33843,63792,0,8,0,13667,0,0,0,'Required quest rewarded for spellclick'),
(18,33843,63792,0,8,0,13686,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,33870,63663,0,8,0,1,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13847,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13851,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13852,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13854,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13855,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13856,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13857,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13858,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13859,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13860,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13861,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13862,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13863,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,8,0,13864,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,34125,63215,0,9,0,13847,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13851,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13852,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13854,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13855,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13856,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13857,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13858,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13859,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13860,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13861,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13862,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13863,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,0,9,0,13864,0,0,0,'Required quest active for spellclick'),
(18,38248,71462,0,1,0,71443,0,0,1,'Forbidden aura for spellclick'),
(18,40176,74904,0,8,0,25444,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,40176,74904,0,9,0,25444,0,0,0,'Required quest active for spellclick'),
(18,40176,74905,0,8,0,25444,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,40176,74905,0,9,0,25444,0,0,0,'Required quest active for spellclick');

-- Below is a procedure to dynamically convert custom content to conditions table.
-- However this procedure only works for MySQL server versions >= 5.6 due to
-- a bug / missing feature in older MySQL versions.

/*

DROP PROCEDURE IF EXISTS ConvertSpellClickConditions;
DELIMITER //
CREATE PROCEDURE ConvertSpellClickConditions()
BEGIN
    DECLARE counter INT DEFAULT 0;
    DECLARE recordCount INT DEFAULT 0;
    DECLARE counterPlusOne INT DEFAULT 0;
    DECLARE npcEntry INT DEFAULT 0;
    DECLARE spellId INT DEFAULT 0;
    DECLARE aura INT DEFAULT 0;
    DECLARE quest INT DEFAULT 0;
    DECLARE quest2 INT DEFAULT 0;
    DECLARE questStartCanActive INT DEFAULT 0;
    DECLARE maxElseGroupId INT DEFAULT 14; -- Change this for custom content
    SELECT COUNT(*) INTO recordCount FROM `npc_spellclick_spells` WHERE `aura_required` !=0;
    WHILE counter < recordCount DO
        SELECT `npc_entry`, `spell_id`, `aura_required`
        INTO npcEntry, spellId, aura
        FROM `npc_spellclick_spells` WHERE `aura_required` !=0
        LIMIT counter,1;
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,1,0,aura,0,0,'Required aura for spellclick');
        SET counter = counter+1;
    END WHILE;

    SET counter = 0;
    SET recordCount = 0;
    SELECT COUNT(*) INTO recordCount FROM `npc_spellclick_spells` WHERE `aura_forbidden` !=0;
    WHILE counter < recordCount DO
        SELECT `npc_entry`, `spell_id`, `aura_forbidden`
        INTO npcEntry, spellId, aura
        FROM `npc_spellclick_spells` WHERE `aura_forbidden` !=0
        LIMIT counter,1;
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,1,0,aura,0,1,'Forbidden aura for spellclick');
        SET counter = counter+1;
    END WHILE;

    SET counter = 0;
    SET recordCount = 0;
    SELECT COUNT(*) INTO recordCount FROM `npc_spellclick_spells` WHERE `quest_start` !=0;
    WHILE counter < recordCount DO
        SELECT `npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`
        INTO npcEntry, spellId, quest, questStartCanActive, quest2
        FROM `npc_spellclick_spells` WHERE `quest_start` !=0
        LIMIT counter,1;
        IF questStartCanActive = 1 AND quest2 = 0 THEN
            INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`, `ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,maxElseGroupId+1,9,0,quest,0,0,'Required quest active for spellclick');
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`, `ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,maxElseGroupId+1,8,0,quest,0,0,'Required quest rewarded for spellclick');
        SET maxElseGroupId = maxElseGroupId+1;
        -- ELSE IF quest2 != 0 is handled in next loop (forbidden rewarded quest)
        ELSEIF questStartCanActive = 1 && quest2 = quest THEN
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,9,0,quest,0,0,'Required quest active for spellclick');
        -- ^Adds the required active quest condition. Prohibit quest reward is done in next loop
        ELSEIF questStartCanActive = 0 THEN
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,8,0,quest,0,0,'Required quest rewarded for spellclick');
        END IF;

        SET counter = counter+1;
    END WHILE;

    SET counter = 0;
    SET recordCount = 0;
    SELECT COUNT(*) INTO recordCount FROM `npc_spellclick_spells` WHERE `quest_end` !=0;
    WHILE counter < recordCount DO
        SELECT `npc_entry`, `spell_id`, `quest_end`
        INTO npcEntry, spellId, quest
        FROM `npc_spellclick_spells` WHERE `quest_end` !=0
        LIMIT counter,1;
        INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,
        `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
        VALUES (18,npcEntry,spellId,8,0,quest,0,1,'Forbidden rewarded quest for spellclick');
        SET counter = counter+1;
    END WHILE;

END//

DELIMITER ;

CALL ConvertSpellClickConditions();
DROP PROCEDURE ConvertSpellClickConditions;

*/

ALTER TABLE `npc_spellclick_spells`
    DROP COLUMN `quest_start`,
    DROP COLUMN `quest_start_active`,
    DROP COLUMN `quest_end`,
    DROP COLUMN `aura_required`,
    DROP COLUMN `aura_forbidden`
;
