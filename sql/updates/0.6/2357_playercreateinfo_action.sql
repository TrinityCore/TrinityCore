ALTER TABLE `playercreateinfo_action` 
  DROP KEY `playercreateinfo_actions_index`,
  ADD KEY `playercreateinfo_actions_index` (`createid`,`button`);

UPDATE `playercreateinfo_action` 
  SET `type` = `misc`;
UPDATE `playercreateinfo_action` 
  SET `misc` = '0';

UPDATE `character_action` 
  SET `type` = `misc`;
UPDATE `character_action` 
  SET `misc` = '0';
