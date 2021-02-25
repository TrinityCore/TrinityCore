UPDATE `smart_scripts` SET `event_param5`= `event_param4` WHERE `event_type`= 74;
UPDATE `smart_scripts` SET `event_param4`= `event_param3` WHERE `event_type`= 74;
UPDATE `smart_scripts` SET `event_param3`= 100 WHERE `event_type`= 74; -- normalizing all existing uses of this smart event to 100 yards
