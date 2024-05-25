import './App.css';
import {Routes,Route} from 'react-router-dom';
import Layout from "./pages/Layout";
import Bonos from './pages/Bonos';
import EntregaDeBonos from './pages/EntregaDeBonos';
import AñadirEntrega from './pages/AñadirEntrega';
import EditarEntrega from './pages/EditarEntrega';
import AltaOdontologo from './pages/AltaOdontologo';
import AltaObraSocial from './pages/AltaObraSocial';
import Inicio from './pages/Inicio';
import Volver from './pages/Volver';
import React, { useEffect, useState, useRef } from 'react';



function App() {
  const [apiData, setApiData] = useState([]);
  const handleDataUpload = (data) => {
    // Esta función se llama cuando se cargan datos en la API
    // Aquí puedes realizar cualquier acción adicional si es necesario
    // Luego, actualiza el estado apiData para desencadenar la recarga de la tabla.
    setApiData([...apiData, data]);
  };

  return (
    <div>
      <Routes>
        <Route path="/" element={<Layout/>}>
          <Route path="/" element={<Inicio/>}/>
          <Route path="Bonos" element={<Bonos/>}/>
          <Route path="EntregaDeBonos" element={<EntregaDeBonos apiData={apiData}/>}/>
          <Route path="AñadirEntrega" element={<AñadirEntrega apiData={apiData}/>}/>
          <Route path="EditarEntrega" element={<EditarEntrega/>}/>
          <Route path="AltaOdontologo" element={<AltaOdontologo/>} />
          <Route path="AltaObraSocial" element={<AltaObraSocial/>} />
          <Route path="/" element={<Volver />} />
        </Route>
      </Routes>
    </div>
  );
}

export default App;
