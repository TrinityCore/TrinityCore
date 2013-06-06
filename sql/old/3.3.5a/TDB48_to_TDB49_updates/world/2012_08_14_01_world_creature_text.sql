DELETE FROM `script_texts` WHERE `npc_entry`=10184;
DELETE FROM `creature_text` WHERE `entry`=10184;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(10184, 0, 0, 'How fortuitous. Usually, I must leave my lair in order to feed.', 14, 0, 100, 0, 0, 0, 'Onyxia - Aggro'),
(10184, 1, 0, 'Learn your place mortal!', 14, 0, 100, 0, 0, 0, 'Onyxia - Kill Player'),
(10184, 2, 0, 'This meaningless exertion bores me. I''ll incinerate you all from above!', 14, 0, 100, 0, 0, 0, 'Onyxia - Phase 2'),
(10184, 3, 0, 'It seems you''ll need another lesson, mortals!', 14, 0, 100, 0, 0, 0, 'Onyxia - Phase 3'),
(10184, 4, 0, '%s takes in a deep breath...', 41, 0, 100, 0, 0, 0, 'Onyxia - Deep Breath Emote');
