update creature_template set gossip_menu_id = 6421, ScriptName = 'npc_riggle_bassbait' where entry = 15077;

delete from creature_questrelation where id = 15077;

delete from creature_text where entry = 15077;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(15077, 0, 0, 'Let the Fishing Tournament BEGIN!', 14, 0, 0, 0, 0, 0, ''),
(15077, 1, 0, 'We have a winner! $n has won FIRST PLACE in the tournament!', 14, 0, 0, 0, 0, 0, ''),
(15077, 2, 0, 'We have a winner! $n has won SECOND PLACE in the tournament!', 14, 0, 0, 0, 0, 0, ''),
(15077, 3, 0, 'We have a winner! $n has won THIRD PLACE in the tournament!', 14, 0, 0, 0, 0, 0, '');

delete from locales_creature_text where entry = 15077;
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(15077, 1, 0, 'А вот и наш победитель! $n занял в состязании ПЕРВОЕ МЕСТО!'),
(15077, 2, 0, 'А вот и наш победитель! $n занял в состязании ВТОРОЕ МЕСТО!'),
(15077, 3, 0, 'А вот и наш победитель! $n занял в состязании ТРЕТЬЕ МЕСТО!');

update gameobject set spawntimesecs = 180 where id = 180248;