-- 查看所有数据库（包括系统数据库）
SELECT name, database_id, create_date, state_desc 
FROM sys.databases;

-- 只查看用户数据库（排除系统数据库）
SELECT name, database_id, create_date, state_desc 
FROM sys.databases 
WHERE database_id > 4; -- 前4个是系统数据库

-- 或者使用更精确的过滤
SELECT name, database_id, create_date, state_desc 
FROM sys.databases 
WHERE name NOT IN ('master', 'model', 'msdb', 'tempdb');

-- 查看所有数据库
EXEC sp_databases;

-- 查看数据库信息（在特定数据库中执行）
USE master;
EXEC sp_helpdb;

-- 查看所有用户表
SELECT name AS table_name, 
       object_id,
       create_date,
       modify_date
FROM sys.tables 
WHERE type = 'U' -- U = User table
ORDER BY name;

-- 或者使用 INFORMATION_SCHEMA（标准SQL方式）
SELECT TABLE_NAME, TABLE_TYPE
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_TYPE = 'BASE TABLE'
ORDER BY TABLE_NAME;

-- 查看当前数据库中的所有对象，包括表
EXEC sp_tables;

-- 只查看用户表
EXEC sp_tables @table_type = "'TABLE'";

