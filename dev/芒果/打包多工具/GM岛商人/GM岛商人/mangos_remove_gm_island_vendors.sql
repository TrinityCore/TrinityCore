--  delete gm islands vendors - spawn - waypath & vendor list
delete from creature_template where entry between 155000 and 155038;
delete from creature where id between 155000 and 155038;
delete from creature_movement where id not in (select guid from creature);
delete from npc_vendor where entry between 155000 and 155038;
delete from creature_template_addon where entry in (155017, 155021, 155022, 155023);
delete from npc_trainer where entry = 155034;