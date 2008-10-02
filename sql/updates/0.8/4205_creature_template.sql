update creature_template set attackpower = round((maxdmg + mindmg) / 4 * 7);
update creature_template set mindmg =  round(mindmg - attackpower / 7);
update creature_template set maxdmg  =  round(maxdmg - attackpower / 7);
update creature_template set mindmg = 1 where mindmg < 1;