UPDATE `creature` c LEFT JOIN `creature_template` ct ON c.id=ct.`Entry` SET c.`MovementType`=0,c.`spawndist`=0 WHERE (ct.flags_extra & 128)!=0;
