-- Active: 1700211904021@@127.0.0.1@3306@ddl_exs

CREATE DATABASE IF NOT EXISTS DDL_and_DML_Exs;

SHOW DATABASES; -- To display all the databases on the currently-connected SQL server
-- Using this command to ensure that we have successfully added our database to the server

USE DDL_Exs; -- any subsequent queries or commands should be executed within the context of this particular database

-- The following are a group of unrelated questions on creating tables. This is not good practice but all these tables are just housed in this exercise database specifically on the data definition language aspect of SQL. Create, alter, drop.

-- Question 1: Create a simple table countries including columns country_id,country_name and region_id.
CREATE TABLE countries ( 
country_id varchar(2),
country_name varchar(40),
region_id decimal(10,0) -- (10, 0) mean 10 numbers to the left of the decimal point and 0 numbers allowed to the right of the decimal point; which is basically another way of saying it's an integer
    -- Notice that we don't put a comma after the last column definition, we just close the parenthesis.
);

-- Question 2: Create a simple table countries including columns country_id,country_name and region_id which is already exists.
CREATE TABLE IF NOT EXISTS countries ( 
    -- IF NOT EXISTS is a condition to make sure that no other table with the same name exists since this is forbidden, it's generally a good practice to always include it when creating a new table or database
country_id varchar(2),
country_name varchar(40),
region_id decimal(10,0)
);

-- Question 3: Create a table named jobs including columns job_id, job_title, min_salary, max_salary and check whether the max_salary amount exceeding the upper limit 25000.
CREATE TABLE IF NOT EXISTS jobs ( 
job_id varchar(10) NOT NULL , 
job_title varchar(35) NOT NULL, 
min_salary decimal(6,0), 
max_salary decimal(6,0) 
CHECK(max_salary<=25000)
);

-- Question 4: Create a table job_history including columns employee_id, start_date, end_date, job_id and department_id and make sure that, the employee_id column does not contain any duplicate value at the time of insertion and the foreign key column job_id contain only those values which are exists in the jobs table.
CREATE TABLE job_history ( 
employee_id decimal(6,0) NOT NULL PRIMARY KEY, 
start_date date NOT NULL, 
end_date date NOT NULL, 
job_id varchar(10) NOT NULL, 
department_id decimal(4,0) DEFAULT NULL, 
FOREIGN KEY (job_id) REFERENCES jobs(job_id)
);

-- Question 5: Rename the table countries to country_new.
ALTER TABLE countries 
RENAME country_new;

-- Question 6: Add a column region_id to the table locations.
ALTER TABLE locations
ADD region_id INT;

-- Question 7: Add a column region_id after state_province to the table locations.
ALTER TABLE locations
ADD region_id INT 
AFTER state_province;

-- Question 8: Change the data type of the column country_id to integer in the table locations.
ALTER TABLE locations
MODIFY country_id INT;

-- Question 9: Drop the column city from the table locations.
ALTER TABLE locations
DROP city;


-- w3resource Questions


-- Question 1 - Write a SQL statement to create the structure of a table dup_countries similar to countries.
CREATE TABLE IF NOT EXISTS dup_countries LIKE countries;

-- Question 2 - Write a SQL statement to create a duplicate copy of countries table including structure and data by name dup_countries.
CREATE TABLE IF NOT EXISTS dup_countries AS SELECT * FROM  countries; 

-- Question 3 - Write a SQL statement to create a table named countries including columns country_id, country_name and region_id and make sure that no countries except Italy, India and China will be entered in the table.
CREATE TABLE IF NOT EXISTS countries ( 
    country_id varchar(2),
    country_name varchar(40) CHECK(COUNTRY_NAME IN('Italy','India','China')) ,
    -- a check constraint that restricts the allowed values to 'Italy', 'India', or 'China'. So, only records with these country names would be allowed in this column.
    region_id decimal(10,0)
);

-- Question 4 - Write a SQL statement to create a table countries including columns country_id, country_name and region_id and make sure that the column country_id will be unique and store an auto incremented value.
CREATE TABLE IF NOT EXISTS countries ( 
    country_id integer NOT NULL UNIQUE AUTO_INCREMENT PRIMARY KEY,
    country_name varchar(40) NOT NULL,
    region_id decimal(10,0) NOT NULL
);

-- Question 5 - Write a SQL statement to create a table countries including columns country_id, country_name and region_id and make sure that the combination of columns country_id and region_id will be unique (aka primary key).ADD
CREATE TABLE IF NOT EXISTS countries (
    country_id varchar(2) NOT NULL UNIQUE DEFAULT '',
    country_name varchar(40) DEFAULT NULL,
    region_id decimal(10,0) NOT NULL,
    CONSTRAINT PRIMARY KEY (country_id,region_id) -- This is a constraint
);

-- Question 6 - Write a SQL statement to create a table named job_history including columns employee_id, start_date, end_date, job_id and department_id and make sure that the value against column end_date will be entered at the time of insertion to the format like '--/--/----'. And make sure that, the employee_id column does not contain any duplicate value at the time of insertion and the foreign key column job_id contain only those values which are exists in the jobs table.
CREATE TABLE IF NOT EXISTS job_history ( 
    employee_id decimal(6,0) NOT NULL PRIMARY KEY, 
    start_date date NOT NULL, 
    end_date date NOT NULL CHECK (end_date LIKE '--/--/----'), 
    job_id INTEGER NOT NULL REFERENCES jobs(job_id), -- Foreign key constraint in the same line (notice that we don't explicitly use the word foreign key)
    department_id decimal(4,0) NOT NULL 
);

-- Question 7 - Write a SQL statement to create a table named jobs including columns job_id, job_title, min_salary and max_salary, and make sure that, the default value for job_title is blank and min_salary is 8000 and max_salary is NULL will be entered automatically at the time of insertion if no value assigned for the specified columns.
CREATE TABLE IF NOT EXISTS jobs ( 
    job_id INTEGER PRIMARY KEY, 
    job_title varchar(35) NOT NULL DEFAULT ' ', 
    min_salary decimal(6,0) DEFAULT 8000, 
    max_salary decimal(6,0) DEFAULT NULL
);

-- Question 8 - Write a SQL statement to create a table departments including column department_id, department_name, manager_id, location_id.
CREATE TABLE IF NOT EXISTS departments (
    department_id DECIMAL(4,0) UNIQUE, 
    department_name TEXT,
    manager_id DECIMAL(6,0) UNIQUE,
    location_id INTEGER(4),
    PRIMARY KEY (department_id, manager_id)
);

-- Question 9 - Write a SQL statement to create a table named 'employees' with the following columns: EMPLOYEE_ID, FIRST_NAME, LAST_NAME, JOB_ID, and SALARY. Ensure that EMPLOYEE_ID is the primary key. Establish a foreign key relationship between the JOB_ID column in the 'employees' table and the JOB_ID column in the 'jobs' table. If a referenced job is deleted or updated, set the corresponding JOB_ID in the 'employees' table to NULL.
CREATE TABLE IF NOT EXISTS employees ( 
    EMPLOYEE_ID decimal(6,0) NOT NULL PRIMARY KEY, 
    FIRST_NAME varchar(20) DEFAULT NULL, 
    LAST_NAME varchar(25) NOT NULL, 
    JOB_ID INTEGER, 
    SALARY decimal(8,2) DEFAULT NULL, 
    FOREIGN KEY(JOB_ID) REFERENCES jobs(job_id) ON DELETE SET NULL ON UPDATE SET NULL
);

-- The following are a group of questions on data manipulation. Inserting, specifically.

-- Question 1: Insert a record with your own value into the table countries against each columns.
INSERT INTO countries (country_id, country_name, region_id)
VALUES('C1','India',1001);

-- Question 2: Insert one row into the table countries against the column country_id and country_name.
INSERT INTO countries (country_id,country_name) 
VALUES('C1','India');

-- Question 3: Insert 3 rows by a single insert statement.
INSERT INTO countries (country_id, country_name, region_id)
VALUES ('C0001','India',1001), ('C0002','USA',1007), ('C0003','UK',1003);