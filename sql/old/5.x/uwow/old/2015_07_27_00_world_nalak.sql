
UPDATE `creature_template` SET `ScriptName` ='npc_essence_of_storm' WHERE (`entry`='69739');

INSERT IGNORE INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`) VALUES
('69099', '0', '0', 'Чувствуете порывы холодного ветра? Приближается буря...', '12', '0', '100', '0', '0', '0'),
('69099', '1', '0', 'Я - сын грома!', '12', '0', '100', '0', '0', '0'),
('69099', '2', '0', 'Сущность гроз вырывается из пронзившего Налака копья и устремляется за вами!', '41', '0', '100', '0', '0', '0');

