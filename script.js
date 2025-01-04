let dataMahasiswa = [];

function tambahMahasiswa() {
    document.getElementById('input-area').style.display = 'block';
    document.getElementById('input-title').innerText = 'Tambah Data Mahasiswa';
    document.getElementById('input-fields').innerHTML = `
        <input type="text" id="nim" placeholder="NIM">
        <input type="text" id="nama" placeholder="Nama">
        <input type="number" id="nilai" placeholder="Nilai Akhir">
    `;
}

function simpanInput() {
    const nim = document.getElementById('nim').value;
    const nama = document.getElementById('nama').value;
    const nilai = parseFloat(document.getElementById('nilai').value);

    if (!nim || !nama || isNaN(nilai)) {
        alert('Data tidak valid!');
        return;
    }

    dataMahasiswa.push({ nim, nama, nilai });
    alert('Data mahasiswa berhasil ditambahkan!');
    document.getElementById('input-area').style.display = 'none';
}

function tampilkanSemua() {
    if (dataMahasiswa.length === 0) {
        document.getElementById('output').innerText = 'Tidak ada data mahasiswa.';
        return;
    }

    let output = '<h3>Data Mahasiswa:</h3>';
    dataMahasiswa.forEach((mhs, index) => {
        output += `${index + 1}. NIM: ${mhs.nim}, Nama: ${mhs.nama}, Nilai: ${mhs.nilai}<br>`;
    });
    document.getElementById('output').innerHTML = output;
}

function cariMahasiswa() {
    const nim = prompt('Masukkan NIM yang ingin dicari:');
    const mahasiswa = dataMahasiswa.find(mhs => mhs.nim === nim);

    if (mahasiswa) {
        document.getElementById('output').innerHTML = `
            <h3>Data Ditemukan:</h3>
            NIM: ${mahasiswa.nim}, Nama: ${mahasiswa.nama}, Nilai: ${mahasiswa.nilai}
        `;
    } else {
        document.getElementById('output').innerText = 'Data tidak ditemukan.';
    }
}

function urutkanData() {
    dataMahasiswa.sort((a, b) => b.nilai - a.nilai);
    alert('Data berhasil diurutkan berdasarkan nilai akhir secara menurun.');
}

function simpanData() {
    const data = JSON.stringify(dataMahasiswa);
    const blob = new Blob([data], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'dataMahasiswa.json';
    a.click();
    URL.revokeObjectURL(url);
}

function bacaData() {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = 'application/json';
    input.onchange = event => {
        const file = event.target.files[0];
        const reader = new FileReader();
        reader.onload = () => {
            dataMahasiswa = JSON.parse(reader.result);
            alert('Data berhasil dimuat dari berkas.');
        };
        reader.readAsText(file);
    };
    input.click();
}
