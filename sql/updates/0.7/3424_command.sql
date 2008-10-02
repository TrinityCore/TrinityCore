UPDATE `command` 
    SET `help` = 'Syntax: .modify $parameter $value Modify the value of various parameters. Use .help modify $parameter to get help on specific parameter usage. Supported parameters include hp, mana, rage, energy, money, speed, swim, scale, bit, bwalk, aspeed, faction, spell and tp.'
    WHERE `name` = 'modify' LIMIT 1 ;

UPDATE `command`
    SET `help` = 'Syntax: .aura #spellid Add the aura from spell #spellid to the selected Unit.'
    WHERE `name` = 'aura' LIMIT 1 ;

UPDATE `command` 
    SET `help` = 'Syntax: .unaura #spellid Remove aura due to spell #spellid from the selected Unit.'
    WHERE `name` = 'unaura' LIMIT 1 ;
