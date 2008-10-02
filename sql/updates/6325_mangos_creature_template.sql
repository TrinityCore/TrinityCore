UPDATE creature_template
  SET flags_extra = flags_extra | 2 WHERE civilian <> 0;

ALTER TABLE `creature_template` 
  DROP civilian;
