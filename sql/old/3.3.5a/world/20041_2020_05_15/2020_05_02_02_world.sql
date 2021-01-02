-- Weapon Crates and Armor Crates should contain only weapons and armor
DELETE FROM `gameobject_loot_template` WHERE
(`Entry` = 404 AND `GroupId` IN (2,4)) OR 
(`Entry` = 405 AND `GroupId` IN (0,2,4)) OR 
(`Entry` = 441 AND `GroupId` IN (0,2,4)) OR 
(`Entry` = 444 AND `GroupId` IN (2,4)) OR 
(`Entry` = 1618 AND `GroupId` IN (2,4)) OR 
(`Entry` = 1619 AND `GroupId` IN (0,2,4));
