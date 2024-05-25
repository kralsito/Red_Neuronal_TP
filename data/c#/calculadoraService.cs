using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using SumaService.service;

namespace SumaService.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class CalculadoraController : ControllerBase
    {
        private readonly CalculadoraService _calculadoraService;

        public CalculadoraController(CalculadoraService calculadoraService)
        {
            _calculadoraService = calculadoraService;
        }

        [HttpGet("sumar")]
        public IActionResult Sumar(int numero1, int numero2)
        {
            try
            {
                int resultado = _calculadoraService.Sumar(numero1, numero2);
                return Ok(resultado);
            }
            catch (Exception ex)
            {
                return BadRequest($"Error: {ex.Message}");
            }
        }
    }

}
