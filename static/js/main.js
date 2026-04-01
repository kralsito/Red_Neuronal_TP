// =============================================
// ELEMENTS
// =============================================
const btn = document.getElementById('analyze-btn');
const loader = document.getElementById('loader');
const resultsDiv = document.getElementById('results');
const mainLang = document.getElementById('main-lang');
const mainProb = document.getElementById('main-prob');
const othersList = document.getElementById('others-list');
const textArea = document.getElementById('code-input');

// =============================================
// API – Analyze Code
// =============================================
btn.addEventListener('click', async () => {
    const code = textArea.value.trim();
    if (!code) return;

    btn.disabled = true;
    loader.style.display = 'inline-block';
    resultsDiv.style.display = 'none';

    try {
        const response = await fetch('/api/analyze', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ code })
        });

        const data = await response.json();
        if (data.predictions) {
            displayResults(data.predictions);
        }
    } catch (error) {
        console.error('Error:', error);
        alert('Ocurrió un error al analizar el código.');
    } finally {
        btn.disabled = false;
        loader.style.display = 'none';
    }
});

// =============================================
// RENDER RESULTS
// =============================================
function displayResults(predictions) {
    const top = predictions[0];
    mainLang.textContent = top.language;
    mainProb.textContent = `${top.probability.toFixed(2)}% de probabilidad`;

    // Low confidence warning
    const warningId = 'confidence-warning';
    let warning = document.getElementById(warningId);
    if (top.probability < 50) {
        if (!warning) {
            warning = document.createElement('div');
            warning.id = warningId;
            warning.className = 'confidence-warning';
            warning.innerHTML = '<i data-lucide="alert-triangle"></i> Baja confianza: el fragmento es ambiguo o muy corto. Prueba con más código.';
            resultsDiv.insertBefore(warning, othersList);
            lucide.createIcons();
        }
    } else if (warning) {
        warning.remove();
    }

    othersList.innerHTML = '';

    predictions.forEach((p, index) => {
        const row = document.createElement('div');
        row.className = 'lang-row';
        row.style.opacity = index === 0 ? '1' : '0.6';

        row.innerHTML = `
            <div class="lang-name">${p.language}</div>
            <div class="progress-container">
                <div class="progress-bar" style="width: 0%"></div>
            </div>
            <div class="lang-prob">${p.probability.toFixed(1)}%</div>
        `;

        othersList.appendChild(row);

        // Trigger bar animation
        setTimeout(() => {
            row.querySelector('.progress-bar').style.width = `${p.probability}%`;
        }, 100 + index * 50);
    });

    resultsDiv.style.display = 'block';
}

// =============================================
// TABS
// =============================================
const tabBtns = document.querySelectorAll('.tab-btn');
const tabContents = document.querySelectorAll('.tab-content');

tabBtns.forEach(tabBtn => {
    tabBtn.addEventListener('click', () => {
        const target = tabBtn.dataset.tab;

        tabBtns.forEach(b => b.classList.remove('active'));
        tabBtn.classList.add('active');

        tabContents.forEach(content => {
            content.classList.remove('active');
            if (content.id === target) content.classList.add('active');
        });

        // Re-render Lucide icons that may appear in newly visible tab
        lucide.createIcons();
    });
});

// =============================================
// INIT
// =============================================
lucide.createIcons();
