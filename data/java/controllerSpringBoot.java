package com.example.proyectoregistro.controllers;

import com.example.proyectoregistro.dto.PersonaDto;
import com.example.proyectoregistro.dto.ReservaDto;
import com.example.proyectoregistro.service.IAsistenciaService;
import com.example.proyectoregistro.service.IReservaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import com.example.proyectoregistro.service.IReservaService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

import java.util.List;

@RestController
public class ReservaController {

    @Autowired
    private IReservaService reservaService;


    @GetMapping("/admin/reservas-pendientes")
    public List<ReservaDto> retornoPendientes() {
        return reservaService.tablaReservaPendiente(); //Devuelve una array de reservas pendientes
    }

    @PostMapping("/admin/reserva")
    public ResponseEntity<Void> addReserva(@RequestBody ReservaDto reservaDto) {
        reservaService.addReserva(reservaDto);
        return ResponseEntity.status(HttpStatus.OK).build();
    }

    @GetMapping("/admin/reservas-confirmadas")
    public ResponseEntity<List<ReservaDto>> getReservaConfirmadas() {
        return ResponseEntity.status(HttpStatus.OK).body(reservaService.getReservasConfirmadas());
    }


    @PostMapping("/admin/reserva/{idReserva}")
    public ResponseEntity<Void> reservar(@PathVariable long idReserva) {
        reservaService.reservar(idReserva);
        return ResponseEntity.status(HttpStatus.OK).build();
    }

    @PostMapping("/admin/reserva/rechazar/{idReserva}")
    public ResponseEntity<Void> rechazarReserva(@PathVariable long idReserva) {
        reservaService.rechazarReserva(idReserva);
        return ResponseEntity.status(HttpStatus.OK).build();
    }

    @PostMapping("/admin/reserva/cancelar/{idReserva}")
    public ResponseEntity<Void> cancelarReserva(@PathVariable long idReserva){
        reservaService.cancelarReserva(idReserva);
        return ResponseEntity.status(HttpStatus.OK).build();
    }
    @PutMapping("/admin/reserva/{idReserva}")
    public ResponseEntity<Void> editarReserva(@PathVariable long idReserva, @RequestBody ReservaDto reservaDto) {
        reservaService.editarReserva(idReserva, reservaDto);
        return ResponseEntity.status(HttpStatus.OK).build();
    }
}

