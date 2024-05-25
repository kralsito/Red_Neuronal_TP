document.addEventListener('DOMContentLoaded', () => {
    const amountInput = document.getElementById('amount');
    const currencySelect = document.getElementById('currency');
    const convertBtn = document.getElementById('convertBtn');
    const resultDisplay = document.getElementById('result');

    convertBtn.addEventListener('click', () => {
        const amount = amountInput.value;
        const currency = currencySelect.value;
        const apiUrl = `https://api.exchangerate-api.com/v4/latest/${currency}`;

        fetch(apiUrl)
            .then(response => response.json())
            .then(data => {
                const rate = data.rates.USD;
                const result = (amount * rate).toFixed(2);
                resultDisplay.textContent = `${amount} ${currency} = ${result} USD`;
            });
    });
});
