import { NodeInfo } from "./node_info.mjs";
import { createElement } from "./utils.mjs";
import { modifyName } from "./add_cards.mjs";
/** 
 * @param {NodeInfo}
 * @returns {string}
*/
function getTagSafeMacAddr(nodeInfo) {
    const nodeId = nodeInfo.mac.replaceAll(':', '_');
    return `${nodeId}`;
}


/** 
 * @param {NodeInfo}
 * @returns {Element}
*/
function generateModal(nodeInfo) {
    const nodeId = getTagSafeMacAddr(nodeInfo);
    const modalId = `staticBackdrop-${nodeId}`;

    const modalFadeDiv = createElement('div', ['modal', 'fade'], modalId, 
        [   ['data-bs-backdrop', 'static'], 
                    ['data-bs-keyboard', 'false'],
                    ['aria-labelledby', 'staticBackdropLabel'], 
                    ['aria-hidden', 'true']]);

    modalFadeDiv.tabIndex = -1;

    const modalDialog = createElement('div', ['modal-dialog']);
    const modalContent = createElement('div', ['modal-content']);
    const modalHeader = createElement('div', ['modal-header']);
    modalHeader.innerHTML = `                        
        <h5 class="modal-title" id="staticBackdropLabel">Editing Node ${nodeInfo.mac}</h5>
        <button type="button" class="btn btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        `;
    
    const modalBody = createElement('div', ['modal-body']);
    const form = generateNodeForm(nodeInfo);
    modalBody.appendChild(form);

    const modalFooter = createElement('div', ['modal-footer']);

    const cancelButton = createElement('button', ['btn', 'btn-secondary'], null, [['type', 'button'], ['data-bs-dismiss', 'modal']]);
    cancelButton.textContent = "Cancel";

    const saveButton = createElement('button', ['btn', 'btn-primary'], null, [['type', 'button'], ['data-bs-dismiss', 'modal'], ['form', `${nodeId}Form`]]);
    saveButton.textContent = "Save Changes";


    modalFooter.appendChild(cancelButton);
    modalFooter.appendChild(saveButton);

    saveButton.addEventListener('click', (e) => {
        // e.preventDefault();
        const myForm = document.querySelector(`#form${nodeId}`);
        const fd = new FormData(myForm);
        const mac = fd.get("mac_address");
        modifyName(mac, fd.get("nodeName"));
        for(const [key, value] of fd.entries()) {
            console.info(`${key}:${value}`);
        }
    return true;
}); 

    modalContent.appendChild(modalHeader);
    modalContent.appendChild(modalBody);
    modalContent.appendChild(modalFooter);

    modalDialog.appendChild(modalContent);
    modalFadeDiv.appendChild(modalDialog);

    return modalFadeDiv;
}


/** 
 * @param {NodeInfo}
 * @returns {string}
*/
function generateNodeCard(nodeInfo) {
    const nodeId = getTagSafeMacAddr(nodeInfo);
    return `
    <div class="col-xl-3 col-sm-6 col-12 mb-4">
    <div class="card" id="${nodeId}">
        <div class="card-header">
            <h5>${nodeInfo.mac} Properties</h5>
        </div>
        <div class="card-body">
            <h5 class="card-title"></h5>
            <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#staticBackdrop-${nodeId}">
                Edit Properties
            </button>
        </div>
    </div>
    </div>
    `;
}



/** 
 * @param {NodeInfo}
 * @returns {Element}
*/
function generateNodeForm(nodeInfo) {
    const nodeId = getTagSafeMacAddr(nodeInfo);
    const formName = `form${nodeId}`;
    const form = document.createElement('form');
    form.id = formName;
    form.innerHTML = `
        <div class="mb-3 row">
            <label for="nodeMacAddress${nodeId}" class="col-sm-2 col-form-label">Node</label>
            <div class="col-sm-10">
                <input class="form-control-plaintext" id="nodeMacAddress${nodeId}" name="mac_address" type="text" value="${nodeInfo.mac}" readonly>
            </div>
        </div>
        <div class="mb-3 row">
            <label for="nodeName${nodeId}" class="col-sm-2 col-form-label">Name</label>
            <div class="col-sm-10">
                <input class="form-control-plaintext" id="nodeName${nodeId}" name="nodeName" type="text" value="${nodeInfo.name}">
            </div>
        </div>
        `;
    return form;
}

export {generateModal, generateNodeCard, generateNodeForm, getTagSafeMacAddr};