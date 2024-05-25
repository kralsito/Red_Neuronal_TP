import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import axios from 'axios';
import '../AO.css';

const AltaOdontologo = () => {
    // Estados para los datos ingresados por el usuario
    const [nombre, setNombre] = useState('');
    const [apellido, setApellido] = useState('');
    const [dni, setDni] = useState('');
    const [matricula, setMatricula] = useState('');
    const [provincia, setProvincia] = useState('');
    const [localidad, setLocalidad] = useState('');
    const [calle, setCalle] = useState('');
    const [codigoPostal, setCodigoPostal] = useState('');
    const [numero, setNumero] = useState('');

    // Estados para las opciones de provincias, localidades y estados
    const [provincias, setProvincias] = useState([]);
    const [localidades, setLocalidades] = useState([]);


    const handleSubmit = async () => {
        const datosOdontologo = {
            nombre,
            apellido,
            dni,
            matricula,
        };
    
        try {
            // Enviar datos del odontólogo al servidor
            const responseOdontologo = await axios.post('https://localhost:5002/Agremiacion/Odontologo/AltaOdontologo', datosOdontologo);
    
            if (responseOdontologo.status === 201) {
                // Si el alta del odontólogo fue exitoso, procedemos con el alta del domicilio
                // El id del odontólogo se puede obtener de la respuesta del servidor si es necesario
                const datosDomicilio = {
                    calle,
                    numero: parseInt(numero), // Convertimos "numero" a un entero
                    localidad,
                    odontologoNombre:`${datosOdontologo.nombre}`,
                    odontologoApellido:`${datosOdontologo.apellido}`
                };
    
                const responseDomicilio = await axios.post('https://localhost:5002/Agremiacion/Domicilio/AltaDomicilio', datosDomicilio);
    
                if (responseDomicilio.status === 201) {
                    // Lógica para manejar una respuesta exitosa
                    console.log('Odontólogo y domicilio agregados exitosamente');
                }
            }
        } catch (error) {
            // Lógica para manejar un error
            console.error('Error al agregar odontólogo y domicilio:', error);
        }
    };
    



    // Obtener la lista de provincias al cargar el componente
    useEffect(() => {
        obtenerProvincias();
        obtenerLocalidades();
    }, []);


    // Obtener la lista de provincias desde el servidor
    const obtenerProvincias = async () => {
        try {
            const response = await axios.get('https://localhost:5002/Agremiacion/Provincia/ListarProvincias');
            setProvincias(response.data);
        } catch (error) {
            console.error('Error al obtener las provincias:', error);
        }
    };

    // Obtener la lista de localidades desde el servidor
    const obtenerLocalidades = async () => {
        try {
            const response = await axios.get('https://localhost:5002/Agremiacion/Localidad/ListarLocalidades');
            setLocalidades(response.data);
        } catch (error) {
            console.error('Error al obtener las localidades:', error);
        }
    };

    return (
        <div className="container">
            <div className="lista">
                <h1>Alta odontólogo</h1>
                <h4>Datos Personales</h4>
                <div className="row">
                    <div>
                        <h4>Nombre</h4>
                        <input id='ao' type="text" value={nombre} onChange={(e) => setNombre(e.target.value)} />
                    </div>
                    <div>
                        <h4>DNI</h4>
                        <input id='ao' type="text" value={dni} onChange={(e) => setDni(e.target.value)} />
                    </div>
                </div>
                <div className="row">
                    <div>
                        <h4>Apellido</h4>
                        <input id='ao' type="text" value={apellido} onChange={(e) => setApellido(e.target.value)} />
                    </div>
                    <div>
                        <h4>Matrícula</h4>
                        <input id='ao' type="text" value={matricula} onChange={(e) => setMatricula(e.target.value)} />
                    </div>
                </div>
                <h4>Domicilio</h4>
                <div className="row">
                    <div>
                        <h4>Provincia</h4>
                        <select value={provincia} onChange={(e) => setProvincia(e.target.value)}>
                            <option value="">Seleccione una provincia</option>
                            {provincias.map((prov) => (
                                <option key={prov.id} value={prov.id}>{prov.nombre}</option>
                            ))}
                        </select>
                    </div>
                    <div>
                        <h4>Localidad</h4>
                        <select value={localidad} onChange={(e) => setLocalidad(e.target.value)}>
                            <option value="">Seleccione una localidad</option>
                            {localidades.map((loc) => (
                                <option key={loc.id} value={loc.id}>{loc.nombre}</option>
                            ))}
                        </select>
                    </div>
                </div>
                <div className="row">
                    <div>
                        <h4>Calle</h4>
                        <input id='ao' type="text" value={calle} onChange={(e) => setCalle(e.target.value)} />
                    </div>
                    <div>
                        <h4>Cod. Postal</h4>
                        <input id='ao' type="text" value={codigoPostal} onChange={(e) => setCodigoPostal(e.target.value)} />
                    </div>
                </div>
                <div className="row">
                    <div>
                        <h4>Número</h4>
                        <input id='ao' type="text" value={numero} onChange={(e) => setNumero(e.target.value)} />
                    </div>
                </div>
                <div className="button-container">
                    <button id="volver"><Link id='link' to="/AñadirEntrega">Cancelar</Link></button>
                    <button id="guardar" onClick={handleSubmit}><Link id='link' to="/AñadirEntrega">Guardar</Link></button>
                </div>
            </div>
        </div>
    );
};

export default AltaOdontologo;