CREATE TABLE categories(
	id SERIAL PRIMARY KEY,
	category_name VARCHAR(255) NOT NULL
);
CREATE TABLE products(
	id SERIAL PRIMARY KEY,
	name VARCHAR(255) NOT NULL,
	price DECIMAL(10,2) NOT NULL CHECK (price >= 0),
	quantity INT NOT NULL CHECK (quantity >= 0),
	category_id INT NOT NULL,
	FOREIGN KEY (category_id) REFERENCES categories(id) ON DELETE CASCADE
);
CREATE TABLE sales(
	id SERIAL PRIMARY KEY,
	product_id INT NOT NULL,
	sale_date DATE NOT NULL,
	quantity_sold INT NOT NULL,
	FOREIGN KEY (product_id) REFERENCES products(id) ON DELETE CASCADE