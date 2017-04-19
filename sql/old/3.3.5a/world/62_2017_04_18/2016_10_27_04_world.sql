--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27056, 2705600, 2705601, 2705602);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27056, 0, 0, 0, 1, 0, 100, 0, 10000, 20000, 3600000, 3600000, 87, 2705600, 2705601, 2705602, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - Out of Combat - Call random script"),
(2705600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 0"),
(2705600, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27055, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 0 (Sentinel Amberline)"),
(2705601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 1"),
(2705601, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 2"),
(2705601, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27052, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 0 (Naohain)"),
(2705602, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 1"),
(2705602, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 3"),
(2705602, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27054, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 0 (Modoru)"),
(2705602, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 27054, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 1 (Modoru)"),
(2705602, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 4"),
(2705602, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 5"),
(2705602, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27119, 0, 0, 0, 0, 0, 0, "Sentinel Sweetspring - On Script - Talk 0 (Snowpaw)");

DELETE FROM `creature_text` WHERE `entry` IN (27056, 27055, 27052, 27054, 27119);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(27056, 0, 0, "%s grins at Sentinel Amberline across the camp, waggling her long eyebrows suggestively.", 16, 0, 100, 0, 0, 0, 29555, 0, "Sentinel Sweetspring"),
(27056, 1, 0, "%s peers at Modoru's Draenic robes.", 16, 0, 100, 0, 0, 0, 27085, 0, "Sentinel Sweetspring"),
(27056, 2, 0, "Pssst. Naohain. Why does Modoru still wear those ridiculous robes? He looks like some interdimensional bumpkin who stumbled out of Ammen Vale not six hours past.", 12, 2, 100, 0, 0, 0, 27086, 0, "Sentinel Sweetspring"),
(27056, 3, 0, "Say, Modoru. Where did you get those... ah... \"wonderful\" robes of yours, hmmm?", 12, 7, 100, 0, 0, 0, 29546, 0, "Sentinel Sweetspring"),
(27056, 4, 0, "Oh. Oh... I see. How nice!", 12, 7, 100, 0, 0, 0, 29547, 0, "Sentinel Sweetspring"),
(27056, 5, 0, "%s bites back a laugh.", 16, 0, 100, 0, 0, 0, 29548, 0, "Sentinel Sweetspring"),
(27055, 0, 0, "%s huffs with annoyance, glaring briefly at Sentinel Sweetspring before turning away with her nose in the air.", 16, 0, 100, 0, 0, 0, 29557, 0, "Sentinel Amberline"),
(27052, 0, 0, "I... I do not know.", 12, 2, 100, 0, 0, 0, 29544, 0, "Naohain"),
(27054, 0, 0, "%s beams, unaware that she is teasing him, answering in his thickly-accented Common.", 16, 0, 100, 0, 0, 0, 29550, 0, "Modoru"),
(27054, 1, 0, "Well! You see, was gift from Grandmother Oluba. She hand-weave from finest silk on Draenor! Am quite proud of, yes.", 12, 7, 100, 0, 0, 0, 29552, 0, "Modoru"),
(27119, 0, 0, "%s snickers, nuzzling into Sentinel Sweetspring's ankles.", 16, 0, 100, 0, 0, 0, 29553, 0, "Snowpaw");
