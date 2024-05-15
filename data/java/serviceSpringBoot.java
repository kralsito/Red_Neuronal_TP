package com.example.proyectoregistro.service;

import com.example.proyectoregistro.dto.AsistenciaDto;
import com.example.proyectoregistro.entities.Asistencia;
import com.example.proyectoregistro.entities.Persona;
import com.example.proyectoregistro.repository.AsistenciaRepository;
import com.example.proyectoregistro.repository.PersonaRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class AsistenciaService implements IAsistenciaService{

    @Autowired
    private AsistenciaRepository asistenciaRepository;

    @Autowired
    private PersonaRepository personaRepository;

    public List<AsistenciaDto> getAsistencias(String nombreUsuario) {
        List<Asistencia> asistencias = asistenciaRepository.findAsistenciasByPersona_Usuario_Nombre(nombreUsuario);

        List<AsistenciaDto> asistenciaDtos = new ArrayList<>();

        for (Asistencia a: asistencias) {
            AsistenciaDto asistenciaDto = new AsistenciaDto(a.getFecha(),a.getHoraInicio(),a.getHoraFin());

            asistenciaDtos.add(asistenciaDto);
        }

        return asistenciaDtos;
    }

    public void registrar(String nombreUsuario, Asistencia asistencia) {
        Persona persona = personaRepository.findPersonaByUsuario_Nombre(nombreUsuario);
        asistencia.setPersona(persona);
        asistenciaRepository.save(asistencia);
    }

    public List<AsistenciaDto> getAsistenciasBecario(long idPersona) {
        List<Asistencia> asistencias = asistenciaRepository.findAsistenciasByPersona_IdPersonaAndPersona_Usuario_Role_Nombre(idPersona,"user");

        List<AsistenciaDto> asistenciaDtos = new ArrayList<>();

        for (Asistencia a: asistencias) {
            AsistenciaDto asistenciaDto = new AsistenciaDto(a.getFecha(),a.getHoraInicio(),a.getHoraFin());

            asistenciaDtos.add(asistenciaDto);
        }

        return asistenciaDtos;
    }
}
