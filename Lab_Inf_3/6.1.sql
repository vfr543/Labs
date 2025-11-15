SELECT 
    c.category_name,
    p.name AS product_name,
    SUM(s.quantity_sold) AS total_sold,
    SUM(s.quantity_sold * p.price) AS total_revenue
FROM sales s
JOIN products p ON s.product_id = p.id
JOIN categories c ON p.category_id = c.id
GROUP BY p.id, p.name, c.category_name
ORDER BY total_sold DESC
LIMIT 5;