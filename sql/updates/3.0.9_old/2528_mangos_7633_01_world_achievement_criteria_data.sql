/*ALTER TABLE db_version CHANGE COLUMN required_7627_01_mangos_achievement_criteria_data required_7633_01_mangos_achievement_criteria_data bit;*/

ALTER TABLE `achievement_criteria_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`criteria_id`,`type`);