删除重复id,站在同一个地方的生物
最容易理解的方法:

--原来一共770884条数据

select min(guid) from creature group by id,position_x, position_y, position_z;--找出id,位置重复的生物数据中guid最小的,即最后要保存的数据.
--656429条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z);--查询要删除的数据.
--114455条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map);
--113895条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map,zoneId);
--95717条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map,zoneId,areaId);
--74692条结果

select * from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z)as x);

--版本1:删除114455条 暴风城NPC也有重复,但是重复的少点 例如暴风城贸易区的工会银行管理员 在此版本中就删除的很好.
--但有个大BUG,把节日NPC也删了,不能使用该版本.


delete from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z,map,zoneId,areaId)as x);
--版本2:74692条 暴风城NPC仍有重复.目前使用版本2的数据

--注意先备份,此处套as是防止mysql报1903错误

来源:https://blog.csdn.net/weixin_39820226/article/details/113553561,其中的方法二
