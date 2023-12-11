const express = require('express');
const knex = require('knex')({
    client: 'mysql2',
    connection: {
        host: 'localhost',
        user: 'root',
        password: 'password',
        database: 'attendance_db'
    }
});

const app = express();
app.use(express.json());
app.use(express.static('public'));

app.get('/api/class-data', async (req, res) => {
    try {
        const classData = await knex('attendance').select('*');
        res.json(classData);
    } catch (error) {
        console.error('Error fetching class data:', error);
        res.status(500).json({ error: 'Internal Server Error' });
    }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
