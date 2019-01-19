/*
TrinityCore Portal Master Option
By Rochet2
Downloaded from http://rochet2.github.io/
Bugs and contact with E-mail: Rochet2@post.com
*/

SET
@NPC_ENTRY := 190000, -- teleporter entry

@MENU_ID := 50000, -- the menu's id, see gossip_menu_option.menu_id
@ID := 1, -- position in menu where you want the option to be in, see gossip_menu_option.id
@ICON := 2,
@TELE_NAME := "Custom Location",
@POPUP := "Are you sure?",

@COST := 0, -- copper
@REQ_LEVEL := 0, -- 0 for no requirement
@FACTION := 0, -- 0 for no req. 469 - Alliance, 67 - Horde.

@MAP := 0,
@X := 0.0,
@Y := 0.0,
@Z := 0.0,
@O := 0.0;

UPDATE `gossip_menu_option` SET `optionid` = `optionid`+1 WHERE `menuid` = @MENU_ID AND `optionid` >= @ID ORDER BY `optionid` DESC;
UPDATE `conditions` SET `SourceEntry` = `SourceEntry`+1 WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = @MENU_ID AND `SourceEntry` >= @ID ORDER BY `SourceEntry` DESC;
UPDATE `smart_scripts` SET `event_param2` = `event_param2`+1 WHERE `entryorguid` = @NPC_ENTRY AND `source_type` = 0 AND `event_param1` = @MENU_ID AND `event_param2` >= @ID ORDER BY `event_param2` DESC;

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, @ID, @ICON, @TELE_NAME, 1, 1, @MENU_ID, @COST, @POPUP);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `Comment`) VALUES
(15, @MENU_ID, @ID, 27, @REQ_LEVEL, 3, 0, CONCAT("Portal Master Level req - ", @TELE_NAME));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `Comment`) VALUES
(15, @MENU_ID, @ID, 6, @FACTION, 0, 0, CONCAT("Portal Master Fact req - ", @TELE_NAME));

SET @SID := (SELECT `id` FROM `smart_scripts` WHERE `entryorguid` = @NPC_ENTRY AND `source_type` = 0 ORDER BY `id` DESC LIMIT 1)+1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@NPC_ENTRY, 0, IFNULL(@SID, 1), 0, 62, 0, 100, 0, @MENU_ID, @ID, 0, 0, 62, @MAP, 0, 0, 0, 0, 0, 7, 0, 0, 0, @X, @Y, @Z, @O, CONCAT("Teleporter script - ", @TELE_NAME));

/*
TrinityCore Portal Master Option
By Rochet2
Downloaded from http://rochet2.github.io/
Bugs and contact with E-mail: Rochet2@post.com
*/
