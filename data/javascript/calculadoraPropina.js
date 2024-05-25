document.addEventListener('DOMContentLoaded', () => {
    const billAmountInput = document.getElementById('billAmount');
    const tipPercentageInput = document.getElementById('tipPercentage');
    const calculateBtn = document.getElementById('calculateBtn');
    const tipAmountDisplay = document.getElementById('tipAmount');
    const totalAmountDisplay = document.getElementById('totalAmount');

    calculateBtn.addEventListener('click', () => {
        const billAmount = parseFloat(billAmountInput.value);
        const tipPercentage = parseFloat(tipPercentageInput.value) / 100;
        const tipAmount = billAmount * tipPercentage;
        const totalAmount = billAmount + tipAmount;
        tipAmountDisplay.textContent = `$${tipAmount.toFixed(2)}`;
        totalAmountDisplay.textContent = `$${totalAmount.toFixed(2)}`;
    });
});
