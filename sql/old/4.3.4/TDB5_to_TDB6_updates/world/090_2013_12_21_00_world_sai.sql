UPDATE `smart_scripts` SET `comment` = REPLACE(`comment`, 'Increment Phase By 0', CONCAT('Increment Phase By ', `action_param1`)) WHERE `comment` LIKE '%Increment Phase By 0%';
