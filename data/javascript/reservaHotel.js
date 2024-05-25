class Room {
    constructor(number, type, price) {
        this.number = number;
        this.type = type;
        this.price = price;
        this.isBooked = false;
    }

    book() {
        if (!this.isBooked) {
            this.isBooked = true;
            console.log(`Habitación ${this.number} reservada.`);
        } else {
            console.log(`Habitación ${this.number} ya está reservada.`);
        }
    }

    cancel() {
        if (this.isBooked) {
            this.isBooked = false;
            console.log(`Reserva de la habitación ${this.number} cancelada.`);
        } else {
            console.log(`Habitación ${this.number} no estaba reservada.`);
        }
    }
}

class Hotel {
    constructor(name) {
        this.name = name;
        this.rooms = [];
    }

    addRoom(number, type, price) {
        let room = new Room(number, type, price);
        this.rooms.push(room);
    }

    listRooms() {
        console.log(`Habitaciones en el Hotel ${this.name}:`);
        this.rooms.forEach(room => {
            console.log(`Número: ${room.number}, Tipo: ${room.type}, Precio: ${room.price}, Reservada: ${room.isBooked}`);
        });
    }
}

const hotel = new Hotel("Hotel California");
hotel.addRoom(101, "Individual", 100);
hotel.addRoom(102, "Doble", 150);
hotel.addRoom(103, "Suite", 250);

hotel.listRooms();
hotel.rooms[1].book();
hotel.rooms[1].book();
hotel.listRooms();
hotel.rooms[1].cancel();
hotel.listRooms();
