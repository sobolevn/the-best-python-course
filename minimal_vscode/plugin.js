(function () {
  function updateTabWithBranch() {
    const branchLabel = document.querySelector(
      '#status\\.scm\\.0 .statusbar-item-label',
    )
    if (!branchLabel) {
      // No `git` or `.git/`, no branch label, or something similar
      return
    }
    const separator = ' | '
    const attrName = 'data-initial-name'

    const tab = document.querySelector('.single-tab .label-description')
    if (!tab) {
      return  // tab might not be there
    }
    
    if (tab.textContent.indexOf(separator) === -1) {
      // Initial case:
      tab.setAttribute(attrName, tab.textContent)
    } 

    // Branch name might be changed, needs an update:
    const originalName = tab.getAttribute(attrName)
    tab.textContent = `${originalName}${separator}${branchLabel.textContent}`
  }

  function updateColumnPosition() {
    const positionLabel = document.querySelector(
      '#status\\.editor\\.selection .statusbar-item-label',
    )
    if (!positionLabel || !positionLabel.textContent) {
      // It might not exist for some reason ¯\_(ツ)_/¯
      return
    }

    const currentLine = document.querySelector(
      '.line-numbers.active-line-number',
    )
    if (!currentLine) {
      return  // It also can be `null` in some cases
    }

    // Now we would have the column position instead of the active line number:
    const colNumber = positionLabel.textContent.match(/Col (\d+)/)
    if (!colNumber) {
      return  // Column was not there
    }
    currentLine.textContent = colNumber[1]
  }

  updateTabWithBranch()
  updateColumnPosition()

  setInterval(updateTabWithBranch, 50)
  setInterval(updateColumnPosition, 50)
})()
