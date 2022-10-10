delete from creature where map = 761;
delete from gameobject where map = 761;

update gameobject_template set faction = 1801 where entry in (180058, 180059);
update gameobject_template set faction = 1802 where entry in (180060, 180061);