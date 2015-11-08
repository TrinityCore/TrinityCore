-- The Exorcism of Colonel Jules
UPDATE `creature_template` SET `ScriptName`= 'npc_barada' WHERE `entry`= 22431;
UPDATE `creature_template` SET `ScriptName`= 'npc_colonel_jules' WHERE `entry`= 22432;

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 8539;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES
(8539, 1, 0, 'I am ready, Anchorite.  Let us begin the exorcism.', 20396, 1, 3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8539;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8539,0,0,9,10935,0,0,0,'','Show gossip menu if player accept Exorcism of Colonel Jules');

DELETE FROM `creature_text` WHERE `entry` IN(22431, 22432);
-- Barada
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22431, 0, 0, 'It is time. The rite of exorcism will now commence...', 12, 0, 100, 0, 0, 0, 20400, 0, 'Barada'),
(22431, 1, 0, 'Prepare yourself. Do not allow the ritual to be interrupted or we may lose our patient...', 12, 0, 100, 0, 0, 0, 20401, 0, 'Barada'),
(22431, 2, 0, 'Back foul beings of darkness! You have no power here!', 12, 0, 100, 0, 0, 0, 20404, 0, 'Barada'),
(22431, 3, 0, 'I... must not... falter', 12, 0, 100, 0, 0, 0, 20407, 0, 'Barada'),
(22431, 4, 0, 'The Light is my guide... it is my sustenance!', 12, 0, 100, 0, 0, 0, 20408, 0, 'Barada'),
(22431, 5, 0, 'The power of light compells you! Back to your pit!', 12, 0, 100, 0, 0, 0, 20405, 0, 'Barada'),
(22431, 6, 0, 'Be cleansed with Light, human! Let not the demonic corruption overwhelm you.', 12, 0, 100, 0, 0, 0, 20403, 0, 'Barada'),
(22431, 7, 0, 'Back! I cast you back... corruptor of faith! Author of pain! Do not return, or suffer the same fate as you did here today!', 12, 0, 100, 0, 0, 0, 20419, 0, 'Barada'),

-- Colonel Jules
(22432, 0, 0, 'Keep away. The fool is mine.', 12, 0, 100, 0, 0, 0, 20402, 0, 'Colonel Jules'),
(22432, 1, 0, 'Ah! Cease the incantations, Anchorite! Cease, or I will show you such pain that your pathetic people have never imagined!', 12, 0, 100, 0, 0, 0, 20414, 0, 'Colonel Jules'),
(22432, 2, 0, 'This is fruitless, draenei! You and your little helper cannot wrest control of this pathetic human. He is mine!', 12, 0, 100, 0, 0, 0, 20416, 0, 'Colonel Jules'),
(22432, 3, 0, 'I see your ancestors, Anchorite! They writhe and scream in the darkness... they are with us!', 12, 0, 100, 0, 0, 0, 20415, 0, 'Colonel Jules'),
(22432, 4, 0, 'I will tear your soul into morsels and slow roast them over demon fire.', 12, 0, 100, 0, 0, 0, 20417, 0, 'Colonel Jules');

-- Aura for the flying skulls
DELETE FROM `creature_template_addon` WHERE `entry` = 22507;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(22507, 0, 0, 0, 1, 0, '39303');
